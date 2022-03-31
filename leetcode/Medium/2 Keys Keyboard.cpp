#include <iostream>
#include <cstring>

using namespace std;

int dp[1005][1005];
int solve(int n, int cur, int buffer)
{
    if(cur == n)
        return 0;
    if(cur > n)
        return 1e8;

    int &ret = dp[cur][buffer];
    if(~ret)
        return ret;

    ret = 1e8;
    if(buffer)
    {
        // paste
        ret = solve(n, cur + buffer, buffer) + 1;
    }
    // cpy and paste
    return ret = min(ret, solve(n, cur + cur, cur) + 2);
}

int minSteps(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(n, 1, 0);

    // Bottom Up
    int dp[1005][1005];
    // Base Case
    for (int i = 0; i < 1005; ++i)
        dp[n][i] = 0;
    // > n
    for (int i = n + 1; i < 1005;++i)
        for (int j = 0; j < 1005;++j)
            dp[i][j] = 1e8;

    for (int cur = n - 1; cur >= 1;--cur)
    {
        for (int buffer = 0; buffer <= n;++buffer)
        {
            dp[cur][buffer] = 1e8;
            if(buffer && cur + buffer <= n)
            {
                dp[cur][buffer] = dp[cur + buffer][buffer] + 1;
            }
            if(cur + cur <= n)
                dp[cur][buffer] = min(dp[cur][buffer], dp[cur + cur][cur] + 2);
        }
    }
    return dp[1][0];
}