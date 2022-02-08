#include <cstring>

using namespace std;

int dp[22];
int solve(int n)
{
    if(n <= 0)
        return 1;
    if(n <= 2)
        return n;

    int &ret = dp[n];
    if(~ret)
        return ret;
    ret = 0;
    for(int i = 1;i<=n;++i)
    {
        // (i-1) left nodes and (n-i) right nodes
        ret += solve(i-1) * solve(n-i);
    }
    return ret;
}

int numTrees(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(1,n);

    // Bottom-Up
    int dp[22];
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for(int state = 3;state<=n;++state)
    {
        for(int j = 1;j<=state;++j)
        {
            dp[state] += dp[j-1] * dp[state-j];
        }
    }
    return dp[n];
}
