#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[2505];
int solve(vector<int>& nums, int pre)
{
    int &ret = dp[pre];
    if(~ret)
        return ret;

    ret = 0;
    for (int i = pre + 1; i < n; ++i)
    {
        if(nums[i] > nums[pre])
        {
            ret = max(ret, solve(nums, i) + 1);
        }
    }
    return ret;
}

int lengthOfLIS(vector<int>& nums)
{
    n = nums.size();
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n;++i)
    {
        ans = max(ans, solve(nums, i) + 1);
    }
    return ans;

    // Bottom-Up
    // int n = nums.size();
    // int dp[2505];
    // int ans = 0;
    // for (int pre = n - 1; pre >= 0; --pre)
    // {
    //     dp[pre] = 1;
    //     for (int i = pre + 1; i < n;++i)
    //     {
    //         if(nums[i] > nums[pre])
    //         {
    //             dp[pre] = max(dp[pre], dp[i] + 1);
    //         }
    //     }
    //     ans = max(ans, dp[pre]);
    // }
    // return ans;
}