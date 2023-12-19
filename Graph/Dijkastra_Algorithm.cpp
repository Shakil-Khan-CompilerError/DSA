#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
const int N = 1e5+7;
const int INF = INT_MAX;
vector<p> adj[N];
vector<int> visited(N);
vector<int> dis(N, INF);

void dijkastra(int source)
{
    priority_queue<p, vector<p>, greater<p>> q;
    dis[source] = 0;
    q.push({dis[source], source});
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        visited[u] = true;
        for(p vPair: adj[u])
        {
            int v = vPair.first;
            int w = vPair.second;
            if(visited[v]) continue;
            if(dis[v] > dis[u]+w)
            {
                dis[v] = dis[u]+w;
                q.push({dis[v], v});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkastra(1);
    for(int i = 1; i <= n; i++)
        cout << "Distance of Node " << i << " : " << dis[i] << "\n";
    return 0;
}
