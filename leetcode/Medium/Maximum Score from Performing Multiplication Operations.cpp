#include <vector>
#include <cstring>

using namespace std;

int n, m;
int dp[1005][1005];
// State should be l, r, and idx, but it will be too large so we calculate r using l and idx. 
// Idx will represent total number of applied operations and l represents total of left operations so we can get number of done right ops.
int solve(vector<int> &nums, vector<int>& multipliers, int l, int idx)
{
    if(idx == m)
        return 0;

    int &ret = dp[l][idx];
    if(~ret)
        return ret;

    int r = n - 1 - (idx - l);
    return ret = max(solve(nums, multipliers, l + 1, idx + 1) + (nums[l] * multipliers[idx]),
        solve(nums, multipliers, l, idx + 1) + (nums[r] * multipliers[idx]));
}

int maximumScore(vector<int>& nums, vector<int>& multipliers)
{
    memset(dp, -1, sizeof(dp));
    n = nums.size();
    m = multipliers.size();
    return solve(nums, multipliers, 0, 0);

    // Bottom-Up
    // Init
    // int dp[1005][1005];
    // int n = nums.size(), m = multipliers.size();
    // for (int i = 0; i <= m;++i)
    //     dp[i][m] = 0;
    // for (int idx = m - 1; idx >= 0; --idx)
    // {
    //     for (int l = idx; l >= 0; --l)
    //     {
    //         int r = n - 1 - (idx - l);
    //         dp[l][idx] = max(nums[l] * multipliers[idx] + dp[l + 1][idx + 1], nums[r] * multipliers[idx] + dp[l][idx + 1]);
    //     }
    // }
    // return dp[0][0];
}