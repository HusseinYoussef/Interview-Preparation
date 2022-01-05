#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[2505];
int solve(vector<int>& nums, int start)
{
    if(start == nums.size())
        return 0;

    int &ret = dp[start];
    if(~ret)
        return ret;

    ret = 0;
    for(int i =start; i < nums.size();++i)
    {
        if(nums[i] > nums[start])
            ret = max(ret, solve(nums, i) + 1);
    }
    return ret;
}

int lengthOfLIS(vector<int>& nums)
{
    int n = nums.size();
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for(int i =0;i<n;++i)
    {
        ans = max(ans, solve(nums, i)+1);
    }
    return ans;
}
