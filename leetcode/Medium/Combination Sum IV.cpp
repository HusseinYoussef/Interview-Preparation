#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[1002];
int solve(vector<int>& nums, int lft)
{
    if(lft == 0)
        return 1;

    int &ret = dp[lft];
    if(~ret)
        return ret;
    
    ret = 0;
    for (int i = 0; i < n;++i)
    {
        if (nums[i] <= lft)
            ret += solve(nums, lft - nums[i]);
    }
    return ret;
}

int combinationSum4(vector<int>& nums, int target)
{
    n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(nums, target);


    // Bottom Up ~ Overflow (Only top down passes)

    // int n = nums.size();
    // int dp[1002];
    // dp[0] = 1;
    // for (int lft = 1; lft <= target;++lft)
    // {
    //     dp[lft] = 0;
    //     for (int i = 0; i < n;++i)
    //     {
    //         if(nums[i] <= lft)
    //         {
    //             dp[lft] += dp[lft - nums[i]];
    //         }
    //     }
    // }
    // return dp[target];
}