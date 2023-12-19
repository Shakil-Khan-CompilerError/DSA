#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int INF = INT_MAX;
vector<pii> adj[N];
vector<int> dis(N, INF);
int n, m;
void bellman_ford(int s)
{
    dis[s] = 0;

    for (int i = 1; i < n; i++)
    {

        for (int u = 1; u <= n; u++)
        {
            for (pii vpair : adj[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if (dis[u] != INF && dis[v] > dis[u] + w)
                    dis[v] = dis[u] + w;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    bellman_ford(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i;
        cout << ": " << dis[i] << endl;
    }
    return 0;
}
