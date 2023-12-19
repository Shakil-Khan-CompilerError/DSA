#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* left, *right;
    Node(int v)
    {
        val = v;
        left = right = NULL;
    }
};
void createBST(Node* &root, int x)
{
    if(root == NULL)
        root = new Node(x);
    else if(x < root->val)
        createBST(root->left, x);
    else if(x > root->val)
        createBST(root->right, x);
}
void levelorderPrintTree(Node *root)
{
    queue<Node* > q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* parent = q.front();
        q.pop();
        cout << parent->val<< " ";
        if(parent->left) q.push(parent->left);
        if(parent->right) q.push(parent->right);
    }
}
bool search(Node* root, int key)
{
    if(root == NULL) return false;
    if(root->val ==  key) return true;
    if(key < root->val) return search(root->left, key);
    else return search(root->right, key);
}
int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        createBST(root, x);
    }
    levelorderPrintTree(root);
    cout << endl << "Search element: ";
    int key;
    cin >> key;
    if(search(root, key)) cout << "Found" << endl;
    else cout << "Not Found!" << endl;
    return 0;
}
