#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[10004];
int solve(vector<int>& coins, int left)
{
    if(left == 0)
        return 0;

    int &ret = dp[left];
    if(~ret)
        return ret;
    ret = 1e8;
    for (int i = 0; i < n;++i)
    {
        if(left - coins[i] >= 0)
        {
            ret = min(ret, solve(coins, left - coins[i]) + 1);
        }
    }
    return ret;
}

int coinChange(vector<int>& coins, int amount)
{
    memset(dp, -1, sizeof(dp));
    n = coins.size();
    int ans = solve(coins, amount);
    return (ans == 1e8) ? -1 : ans;

    // Bottom Up
    // int n = coins.size();
    // int dp[10004];
    // dp[0] = 0;
    // for (int left = 1; left <= amount;++left)
    // {
    //     dp[left] = 1e8;
    //     for (int i = 0; i < n;++i)
    //     {
    //         if(left - coins[i] >= 0)
    //         {
    //             dp[left] = min(dp[left], dp[left - coins[i]] + 1);
    //         }
    //     }
    // }
    // return (dp[amount] == 1e8) ? -1 : dp[amount];
}