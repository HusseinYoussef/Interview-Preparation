#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[100005][4];
int solve(vector<vector<int>> &costs, int idx, int pre)
{
    if(idx == n)
        return 0;

    int &ret = dp[idx][pre];
    if(~ret)
        return ret;

    ret = 1e8;
    for (int c = 1; c <= 3;++c)
    {
        if(c != pre)
            ret = min(ret, solve(costs, idx + 1, c) + costs[idx][c - 1]);
    }
    return ret;
}

int minCost(vector<vector<int>> &costs)
{
    memset(dp, -1, sizeof(dp));
    n = costs.size();
    return solve(costs, 0, 0);

    // Bottom-Up
    int n = costs.size();
    int dp[100005][4];
    memset(dp, 0, sizeof(dp));
    for (int idx = n - 1; idx >= 0;--idx)
    {
        dp[idx][0] = min(dp[idx + 1][1], dp[idx + 1][2]) + costs[idx][0];
        dp[idx][1] = min(dp[idx + 1][0], dp[idx + 1][2]) + costs[idx][1];
        dp[idx][2] = min(dp[idx + 1][0], dp[idx + 1][1]) + costs[idx][2];
    }
    return min(dp[0][0], min(dp[0][1], dp[0][2]));
}