
/*
    Problem Statement

    Given an array of distinct positive integers representing coin denominations and a
    single non-negative integer n representing a target amount of
    money, write a function that returns the number of ways to make change for
    that target amount using the given coin denominations.
    
    Note that an unlimited amount of coins is at your disposal.
*/

#include <vector>
#include <cstring>
using namespace std;

// idx, change left
int dp[105][1005];
int solve(vector<int> &denoms, int idx, int lft)
{
    if(lft == 0)
        return 1;
    
    if(lft < 0 || idx == denoms.size())
        return 0;

    int &ret = dp[idx][lft];
    if(~ret)
        return ret;

    return solve(denoms, idx + 1, lft) + solve(denoms, idx, lft - denoms[idx]);
}

int numberOfWaysToMakeChange(int n, vector<int> denoms)
{
    memset(dp, -1, sizeof(dp));
    return solve(denoms, 0, n);

    int dp[105][1005];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 105;++i)
        dp[i][0] = 1;

    for (int idx = denoms.size() - 1;idx>=0;--idx)
    {
        for (int lft = 1; lft <= n;++lft)
        {
            dp[idx][lft] = dp[idx + 1][lft];
            if(denoms[idx] <= lft)
                dp[idx][lft] += dp[idx][lft - denoms[idx]];
        }
    }
    return dp[0][n];

    int dp[2][1005];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = dp[1][0] = 1;

    bool roll = 0;
    for (int idx = denoms.size() - 1;idx>=0;--idx)
    {
        for (int lft = 1; lft <= n;++lft)
        {
            dp[roll][lft] = dp[!roll][lft];
            if(denoms[idx] <= lft)
                dp[roll][lft] += dp[roll][lft - denoms[idx]];
        }
        roll = !roll;
    }
    return dp[!roll][n];
}
