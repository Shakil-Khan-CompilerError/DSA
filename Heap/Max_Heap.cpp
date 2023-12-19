#include <bits/stdc++.h>
using namespace std;

vector<int> v;
void makeHeap(int x, int idx)
{
    int parent = (idx - 1) / 2;
    if (parent < 0)
        return;
    if (v[parent] < x)
    {
        swap(v[parent], v[idx]);
        makeHeap(v[parent], parent);
    }
}
void deleteFromHeap(int idx)
{
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    if (left < v.size() && right < v.size())
    {
        int max = left;
        if (v[left] < v[right])
            max = right;
        if(v[idx] < v[max])
        {
            swap(v[idx], v[max]);
            deleteFromHeap(max);
        }
    }
    else if (left < v.size())
    {
        if (v[idx] < v[left])
        {
            swap(v[idx], v[left]);
            deleteFromHeap(left);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        makeHeap(x, i);
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    while (1)
    {
        if (v.size() == 0)
            break;
        int flag;
        cout << "enter 0 for exit, 1 for delete" << endl;
        cin >> flag;
        if (flag == 0)
            break;
        v[0] = v[v.size() - 1];
        v.pop_back();
        deleteFromHeap(0);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
