#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[5005][2];
int solve(vector<int>& prices, int idx, bool holdStock)
{
    if(idx >= n)
        return 0;

    int &ret = dp[idx][holdStock];
    if(~ret)
        return ret;

    ret = 0;
    // buy or not
    if(holdStock == 0)
        return ret = max(ret, max(solve(prices, idx + 1, 0), solve(prices, idx + 1, 1) - prices[idx]));
    // sell or not
    return ret = max(ret, max(solve(prices, idx + 1, 1), solve(prices, idx + 2, 0) + prices[idx]));
}

int maxProfit(vector<int>& prices)
{
    memset(dp, -1, sizeof(dp));
    n = prices.size();
    return solve(prices, 0, 0);

    // Bottom-Up
    // int n = prices.size();
    // int dp[5005][2];
    // memset(dp, 0, sizeof(dp));
    // for (int idx = n - 1; idx >= 0; --idx)
    // {
    //     // holdStock = 0
    //     dp[idx][0] = max(dp[idx][0], max(dp[idx + 1][0], dp[idx + 1][1] - prices[idx]));
    //     // holdStock = 1
    //     dp[idx][1] = max(dp[idx][1], max(dp[idx + 1][1], dp[idx + 2][0] + prices[idx]));
    // }
    // return dp[0][0];
}