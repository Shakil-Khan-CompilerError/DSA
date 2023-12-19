#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int v[N], dp[N][N];
int maxWays(int n, int s)
{
    if(s == 0) return 1;
    if(n < 0) return 0;
    if(dp[n][s] != -1) return dp[n][s];
    if(s >= v[n])
        return dp[n][s] = maxWays(n, s-v[n]) + maxWays(n-1, s);
    else return dp[n][s] = maxWays(n-1, s);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, total;
    cin >> n >> total;
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << maxWays(n-1, total);
    return 0;
}
