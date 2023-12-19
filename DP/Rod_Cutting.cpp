#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int v[N], dp[N][N];
int Uknapsack(int n, int s)
{
    if(n == 0 || s == 0) return 0;
    if(dp[n][s] != -1) return dp[n][s];
    if(s >= n)
        return dp[n][s] = max(v[n]+Uknapsack(n, s-n), Uknapsack(n-1, s));
    else return dp[n][s] = Uknapsack(n-1, s);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    cout << Uknapsack(n, n) << "\n";
    return 0;
}
