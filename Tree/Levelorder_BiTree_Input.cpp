#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};
void levelorderTraverse(Node* root)
{
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* f = q.front();
        q.pop();
        cout << f->val << " ";
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}
Node* input()
{

    queue<Node*> q;
    Node* root;
    int val;
    cin >> val;
    if(val == -1) root = NULL;
    else root = new Node(val);
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();

        int l, r;
        Node* left, *right;
        cin >> l >> r;
        if(l == -1) left = NULL;
        else left = new Node(l);
        if(r == -1) right = NULL;
        else right = new Node(r);
        p->left = left;
        p->right = right;

        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}
int main()
{
    Node* root = input();
    levelorderTraverse(root);
    return 0;
}
