#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[1005][105][2];
int solve(vector<int>& prices, int idx, int k, bool holdStock)
{
    if(idx == n || k == 0)
        return 0;

    int &ret = dp[idx][k][holdStock];
    if(~ret)
        return ret;

    ret = 0;
    // buy or not
    if(holdStock == 0)
        return ret = max(ret, max(solve(prices, idx + 1, k, 0), solve(prices, idx + 1, k, 1) - prices[idx]));
    // sell or not
    return ret = max(ret, max(solve(prices, idx + 1, k, 1), solve(prices, idx + 1, k - 1, 0) + prices[idx]));
}

int maxProfit(int k, vector<int>& prices)
{
    memset(dp, -1, sizeof(dp));
    n = prices.size();
    return solve(prices, 0, k, 0);

    // Bottom-Up
    // int n = prices.size();
    // int dp[1005][105][2];
    // memset(dp, 0, sizeof(dp));
    // for (int tr = 1; tr <= k;++tr)
    // {
    //     for (int idx = n - 1; idx >= (k - tr) * 2; --idx)
    //     {
    //         // holdStock = 0
    //         dp[idx][tr][0] = max(dp[idx][tr][0], max(dp[idx + 1][tr][0], dp[idx + 1][tr][1] - prices[idx]));
    //         // holdStock = 1
    //         dp[idx][tr][1] = max(dp[idx][tr][1], max(dp[idx + 1][tr][1], dp[idx + 1][tr - 1][0] + prices[idx]));
    //     }
    // }
    // return dp[0][k][0];
}