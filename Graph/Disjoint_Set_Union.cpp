#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int parent[N];
int Size[N];
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}
int find(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        make(i);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    int connected_comp = 0;
    for (int i = 1; i <= n; i++)
        if(find(i) == i) connected_comp++;
    cout << connected_comp << "\n";
    return 0;
