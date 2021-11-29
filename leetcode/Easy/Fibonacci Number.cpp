#include <iostream>
#include <cstring>

using namespace std;

int fib(int n)
{
    int dp[32];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n;++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}