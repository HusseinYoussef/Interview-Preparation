
/*
    Problem Statement

    Given an array of positive integers representing coin denominations and a
    single non-negative integer n representing a target amount of
    money, write a function that returns the smallest number of coins needed to
    make change for (to sum up to) that target amount using the given coin
    denominations.

    Note that you have access to an unlimited amount of coins. In other words, if
    the denominations are 
    If it's impossible to make change for the target amount, return -1
*/

#include <vector>
#include <cstring>
using namespace std;

int dp[105][1005];
// O(nd) Time, O(nd) Space
int solve(vector<int> &denoms, int idx, int lft)
{
    if(lft == 0)
        return 0;
    if(idx == denoms.size() || lft < 0)
        return 1e8;

    int &ret = dp[idx][lft];
    if(~ret)
        return ret;

    return ret = min(solve(denoms, idx + 1, lft), solve(denoms, idx, lft - denoms[idx]) + 1);
}

int minNumberOfCoinsForChange(int n, vector<int> denoms)
{
    memset(dp, -1, sizeof(dp));
    int ans = solve(denoms, 0, n);
    if(ans == 1e8)
        return -1;
    return ans;

    // O(nd) Time, O(nd) Space
    int dp[105][1005];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 1005;++i)
        dp[denoms.size()][i] = 1e8;

    for (int idx = denoms.size() - 1; idx >= 0;--idx)
    {
        for (int lft = 1; lft <= n;++lft)
        {
            dp[idx][lft] = dp[idx + 1][lft];
            if(denoms[idx] <= lft)
                dp[idx][lft] = min(dp[idx][lft], dp[idx][lft - denoms[idx]] + 1);
        }
    }
    if(dp[0][n] == 1e8)
        return -1;
    return dp[0][n];

    // O(nd) Time, O(n) Space
    int dp[2][1005];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < 1005;++i)
        dp[1][i] = 1e8;

    bool roll = 0;
    for (int idx = denoms.size() - 1; idx >= 0;--idx)
    {
        for (int lft = 1; lft <= n;++lft)
        {
            dp[roll][lft] = dp[!roll][lft];
            if(denoms[idx] <= lft)
                dp[roll][lft] = min(dp[roll][lft], dp[roll][lft - denoms[idx]] + 1);
        }
        roll = !roll;
    }
    if(dp[!roll][n] == 1e8)
        return -1;
    return dp[!roll][n];
}