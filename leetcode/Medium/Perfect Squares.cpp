#include <iostream>
#include <cstring>

using namespace std;

int dp[10004];
int solve(int sum)
{
    if(sum == 0)
        return 0;

    int &ret = dp[sum];
    if(~ret)
        return ret;

    ret = 1e7;
    for (int i = 1; i * i <= sum;++i)
        ret = min(ret, solve(sum - i * i) + 1);
    return ret;
}

int numSquares(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(n);

    // Bottom Up
    int dp[10004];
    dp[0] = 0;
    for (int sum = 1; sum <= n;++sum)
    {
        dp[sum] = 1e7;
        for (int i = 1; i * i <= sum;++i)
        {
            dp[sum] = min(dp[sum], dp[sum - i * i] + 1);
        }
    }
    return dp[n];
}