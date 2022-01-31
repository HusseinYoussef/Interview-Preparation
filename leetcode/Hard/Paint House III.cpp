#include <vector>
#include <cstring>

using namespace std;

int dp[105][105][25];
int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int idx, int hoods, int preColor)
{
    if(idx == m && hoods == target)
        return 0;
    if(idx == m || hoods > target)
        return 1e8;

    int &ret = dp[idx][hoods][preColor];
    if(~ret)
        return ret;
    
    if(houses[idx] != 0)
        return ret = solve(houses, cost, m, n, target, idx + 1, hoods + (houses[idx] != preColor), houses[idx]);

    ret = 1e8;
    for (int c = 1; c <= n;++c)
    {
        ret = min(ret, solve(houses, cost, m, n, target, idx + 1, hoods + (c != preColor), c) + cost[idx][c - 1]);
    }
    return ret;
}

int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
{
    memset(dp, -1, sizeof(dp));
    int ans = solve(houses, cost, m, n, target, 0, 0, 0);
    if(ans == 1e8)
        return -1;
    return ans;

    // Bottom-Up
    int dp[105][105][25];
    // Init
    for (int i = 0; i < 105;++i)
        for (int j = 0; j < 105;++j)
            for (int k = 0; k < 25;++k)
                dp[i][j][k] = 1e8;

    for (int i = 0; i < 25;++i)
        dp[m][target][i] = 0;
    for (int idx = m - 1; idx >= 0; --idx)
    {
        for (int hoods = target; hoods >= 0; --hoods)
        {
            for (int preColor = 0; preColor <= n; ++preColor)
            {
                if (houses[idx] != 0)
                {
                    dp[idx][hoods][preColor] = dp[idx + 1][hoods + (houses[idx] != preColor)][houses[idx]];
                    continue;
                }
                for (int c = 1; c <= n; ++c)
                {
                    dp[idx][hoods][preColor] = min(dp[idx][hoods][preColor], dp[idx + 1][hoods + (c != preColor)][c] + cost[idx][c - 1]);
                }
            }
        }
    }
    if(dp[0][0][0] == 1e8)
        return -1;
    return dp[0][0][0];
}