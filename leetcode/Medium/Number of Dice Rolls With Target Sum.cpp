#include <cstring>

using namespace std;

int mod = 1e9 + 7;
int dp[35][1005];
int solve(int n, int k, int target, int idx, int sum)
{
    if(idx == n && sum == target)
        return 1;
    if(idx == n)
        return 0;

    int &ret = dp[idx][sum];
    if(~ret)
        return ret;

    ret = 0;
    for (int i = 1; i <= k;++i)
    {
        if(sum + i <= target)
            ret = ((ret % mod) + (solve(n, k, target, idx + 1, sum + i) % mod)) % mod;
    }
    return ret;
}

int numRollsToTarget(int n, int k, int target)
{
    memset(dp, -1, sizeof(dp));
    return solve(n, k, target, 0, 0);

    // Bottom-Up
    int dp[35][1005];
    memset(dp, 0, sizeof(dp));
    dp[n][target] = 1;
    for (int idx = n - 1; idx >= 0;--idx)
    {
        for (int sum = target - 1; sum >= 0;--sum)
        {
            for (int i = 1; i <= k; ++i)
            {
                if(sum + i <= target)
                {
                    dp[idx][sum] = ((dp[idx][sum] % mod) + (dp[idx + 1][sum + i] % mod)) % mod;
                }
            }
        }
    }
    return dp[0][0];
}