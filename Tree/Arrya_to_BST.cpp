#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;
    Node(int v)
    {
        val = v;
        left = right = NULL;
    }
};
void convertToBST(Node *&root, int arr[], int l, int r)
{
    if(l > r) return;
    int mid = (l + r) / 2;
    if (root == NULL)
        root = new Node(arr[mid]);
    convertToBST(root->left, arr, l, mid - 1);
    convertToBST(root->right, arr, mid + 1, r);
}
void levelorderPrintTree(Node *root)
{
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();
        cout << parent->val << " ";
        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    Node *root = NULL;
    convertToBST(root, arr, 0, n - 1);
    levelorderPrintTree(root);
    return 0;
}
