#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[1005][2005];
int solve(int idx, int k, vector<vector<int>>& piles)
{
    if (idx >= n || k == 0)
        return 0;

    int &ret = dp[idx][k];
    if (~ret)
        return ret;

    ret = solve(idx + 1, k, piles);
    int sum = 0;
    for(int i = 0;i<min(k, (int)piles[idx].size());++i)
    {
        sum += piles[idx][i];
        ret = max(ret, solve(idx + 1, k - i - 1, piles) + sum);
    }

    return ret;
}

int maxValueOfCoins(vector<vector<int>>& piles, int k)
{
    n = piles.size();
    // memset(dp, -1, sizeof(dp));
    // return solve(0, k, piles);

    int dp[1005][2005];
    memset(dp, 0, sizeof(dp));
    for(int idx = n-1; idx >= 0; --idx)
    {
        for(int left = 1; left <= k; ++left)
        {
            int sum = 0;
            for (int i = 0;i<min(left, (int)piles[idx].size()); ++i)
            {
                sum += piles[idx][i];
                dp[idx][left] = max(dp[idx][left], dp[idx+1][left - i - 1] + sum);
            }
            dp[idx][left] = max(dp[idx][left], dp[idx+1][left]);
        }
    }
    return dp[0][k];
}
