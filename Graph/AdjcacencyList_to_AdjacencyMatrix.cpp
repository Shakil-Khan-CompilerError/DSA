#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+4;
int adjMatrix[N][N];
vector<int> adjList[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    for(int i = 1; i <= n; i++)
        for(int j: adjList[i])
            adjMatrix[i][j] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << adjMatrix[i][j] <<" ";
        cout << endl;
    }

    return 0;
}
