#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[10004];
int solve(vector<int>& coins, int left)
{
    if(left == 0)
        return 0;

    int &ret = dp[left];
    if(~ret)
        return ret;

    int res = 1000005;
    for (int i = 0; i < coins.size();++i)
    {
        if(coins[i] <= left)
        {
            res = min(res, solve(coins, left - coins[i]) + 1);
        }
    }
    return ret = res;
}

int coinChange(vector<int>& coins, int amount)
{
    memset(dp, -1, sizeof(dp));
    int ans = solve(coins, amount);
    if(ans == 1000005)
        return -1;
    return ans;
}