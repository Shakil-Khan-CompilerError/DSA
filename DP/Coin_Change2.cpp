#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
const int INF = 1e9;
int coin[N], dp[N][N];
int minCoin(int n, int s)
{
    if(s == 0) return 0;
    if(n < 0) return INF;
    if (dp[n][s] != -1) return dp[n][s];
    if(s >= coin[n])
        return dp[n][s] = min(1+minCoin(n, s-coin[n]), minCoin(n-1, s));
    else return dp[n][s] = minCoin(n-1, s);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, total;
    cin >> n >> total;
    for(int i = 0; i < n; i++) cin >> coin[i];
    cout << minCoin(n-1, total) << "\n";
    return 0;
}

