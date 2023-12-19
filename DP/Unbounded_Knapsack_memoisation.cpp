#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int v[N], w[N];
int dp[N][N];
int Uknapsack(int n, int s)
{
    if(s == 0 || n < 0) return 0;
    if(dp[n][s] != -1) return dp[n][s];
    if(s >= w[n])
        return dp[n][s] = max(Uknapsack(n, s-w[n])+v[n], Uknapsack(n-1, s));
    else return dp[n][s] = Uknapsack(n-1, s);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, W;
    cin >> n >> W;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> w[i];
    cout << Uknapsack(n-1, W) << "\n";
    return 0;
}
