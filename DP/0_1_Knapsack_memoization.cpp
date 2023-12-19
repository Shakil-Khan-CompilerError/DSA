#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int w[N], v[N];
int dp[1005][1005];
int knapsack(int n, int W)
{
    if (n < 0 || W == 0) return 0;
    if(dp[n][W] != -1) return dp[n][W];
    if (W >= w[n])
    {
        int choice1 = knapsack(n - 1, W - w[n]) + v[n];
        int choice2 = knapsack(n - 1, W);
        return dp[n][W] = max(choice1, choice2);
    }
    else return dp[n][W] = knapsack(n - 1, W);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> w[i];
    int value = knapsack(n - 1, W);
    cout << value << endl;
    return 0;
}
