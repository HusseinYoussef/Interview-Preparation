#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[305][5005];
int solve(vector<int>& coins, int idx, int left)
{
    if(idx == n)
        return 0;
    if(left == 0)
        return 1;

    int &ret = dp[idx][left];
    if(~ret)
        return ret;

    ret = 0;
    if(coins[idx] <= left)
        ret = solve(coins, idx, left - coins[idx]);
    return ret += solve(coins, idx + 1, left);
}

int change(int amount, vector<int>& coins)
{
    memset(dp, -1, sizeof(dp));
    n = coins.size();
    return solve(coins, 0, amount);

    // Bottom-Up
    // int n = coins.size();
    // int dp[305][5005];
    // memset(dp, 0, sizeof(dp));
    // for (int i = 0; i <= 300;++i)
    //     dp[i][0] = 1;

    // for (int left = 1; left <= amount; ++left)
    // {
    //     for (int idx = n - 1; idx >= 0; --idx)
    //     {
    //         if(coins[idx] <= left)
    //         {
    //             dp[idx][left] = dp[idx][left - coins[idx]];
    //         }
    //         dp[idx][left] += dp[idx + 1][left];
    //     }
    // }
    // return dp[0][amount];

    // Rolling O(amount) Space
    // int n = coins.size();
    // int dp[2][5005];
    // memset(dp, 0, sizeof(dp));
    // dp[0][0] = dp[1][0] = 1;

    // bool roll = 0;
    // for (int idx = n - 1; idx >= 0;--idx)
    // {
    //     for (int left = 1; left <= amount;++left)
    //     {
    //         dp[roll][left] = dp[!roll][left];
    //         if(coins[idx] <= left)
    //             dp[roll][left] += dp[roll][left - coins[idx]];
    //     }
    //     roll = !roll;
    // }
    // return dp[!roll][amount];
}