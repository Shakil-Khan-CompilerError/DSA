#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int dp[N][N];
int lcs(string a, int n, string b, int m)
{
    if(n < 0 || m < 0) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(a[n] == b[m])
        return dp[n][m] = 1 + lcs(a, n-1, b, m-1);
    else
        return dp[n][m] = max(lcs(a, n, b, m-1), lcs(a, n-1, b, m));
}
int main()
{
    memset(dp, -1, sizeof(dp));
    string a, b;
    cin  >> a >> b;
    cout << lcs(a, a.size()-1, b, b.size()-1) <<"\n";
    return 0;
}
