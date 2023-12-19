#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;
    int v[n], w[n];
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> w[i];
    int dp[n+1][W+1];
    for(int i = 0; i <= W; i++) dp[0][i] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= W; j++)
            if (j >= w[i-1])
                dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
    }
    cout << dp[n][W] << "\n";
    return 0;
}
