#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+4;
int adjMatrix[N][N];
vector<int> adjList[N];
int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> adjMatrix[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(adjMatrix[i][j])
                adjList[i].push_back(j);
    for(int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for(int j: adjList[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
