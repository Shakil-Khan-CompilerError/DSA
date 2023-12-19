#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int a[N];
int dp[N][N];
bool check(int n, int s)
{
    if(s == 0) return true;
    if(n < 0) return false;
    if(dp[n][s] != -1) return dp[n][s];
    if(s >= a[n])
    {
        return dp[n][s] = (check(n-1, s-a[n]) || check(n-1, s));
    }
    else return dp[n][s] = check(n-1, s);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, sum;
    cin >> n >> sum;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(check(n-1, sum)) cout << "YES";
    else cout << "NO";
    return 0;
}
