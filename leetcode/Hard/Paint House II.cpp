#include <vector>
#include <cstring>

using namespace std;

int n, k;
int dp[10005][105];
int solve(vector<vector<int>> &costs, int idx, int pre)
{
    if(idx == n)
        return 0;

    int &ret = dp[idx][pre];
    if(~ret)
        return ret;

    ret = 1e8;
    for (int c = 1; c <= k;++c)
    {
        if(c != pre)
            ret = min(ret, solve(costs, idx + 1, c) + costs[idx][c - 1]);
    }
    return ret;
}

int minCostII(vector<vector<int>> &costs)
{
    //*** Top-Down = TLE ****

    // n = costs.size();
    // if(n == 0)
    //     return 0;
    // k = costs[0].size();
    // memset(dp, -1, sizeof(dp));
    // return solve(costs, 0, 0);

    // Bottom-Up O(N*K*K)
    int n = costs.size();
    if(n == 0)
        return 0;
    int k = costs[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    // Init
    for (int i = 0; i < k;++i)
        dp[n - 1][i] = costs[n - 1][i];
    for (int idx = n - 2; idx >= 0; --idx)
    {
        for (int c = 0; c < k; ++c)
        {
            int mn = 1e8;
            for (int i = 0; i < k; ++i)
            {
                if (i == c)
                    continue;
                mn = min(mn, dp[idx + 1][i]);
            }
            dp[idx][c] = mn + costs[idx][c];
        }
    }
    int ans = 1e8;
    for (int i = 0; i < k;++i)
        ans = min(ans, dp[0][i]);
    return ans;
}