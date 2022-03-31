#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int n;
int dp[1002][52];
// O(N^2 * M)
int solve(vector<int>& nums, vector<int>& cum, int idx, int lft)
{
    if(lft == 0)    // take from idx to the end of array
    {
        return cum[n - 1] - ((idx > 0) ? cum[idx - 1] : 0);
    }

    int &ret = dp[idx][lft];
    if(~ret)
        return ret;

    ret = INT_MAX;
    int sum = 0;
    for (int i = idx; i < n - lft;++i)
    {
        sum += nums[i];
        ret = min(ret, max(sum, solve(nums, cum, i + 1, lft - 1)));
    }
    return ret;
}

int splitArray(vector<int>& nums, int m)
{
    n = nums.size();
    vector<int> cum(n, 0);
    cum[0] = nums[0];
    for (int i = 1; i < n;++i)
        cum[i] = nums[i] + cum[i - 1];

    memset(dp, -1, sizeof(dp));
    return solve(nums, cum, 0, m - 1);

    // Bottom Up

    int dp[1002][52];
    // Base Case
    for (int i = 0; i < n;++i)
    {
        dp[i][0] = cum[n - 1] - ((i > 0) ? cum[i - 1] : 0);
    }

    for (int idx = n - 1; idx >= 0; --idx)
    {
        for (int lft = 1; lft < m;++lft)
        {
            dp[idx][lft] = INT_MAX;
            int sum = 0;
            for (int i = idx; i < n - lft;++i)
            {
                sum += nums[i];
                dp[idx][lft] = min(dp[idx][lft], max(sum, dp[i + 1][lft - 1]));
            }
        }
    }
    return dp[0][m - 1];
}