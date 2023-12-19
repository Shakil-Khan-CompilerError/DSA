#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
bool visited[N];
int height[N];

void dfs(int u, int node)
{
    visited[u] = true;
    for (int v : adjList[u])
    {
        if (visited[v]) continue;
        dfs(v, node);
        height[u] = max(height[u], height[v] + 1);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int node;
    cin >> node;
    dfs(1, node);
    cout << "height of " << node << " = " << height[node] <<endl;
    return 0;
}
