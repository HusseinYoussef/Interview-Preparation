#include <iostream>
#include <vector>

using namespace std;

int dp[202][10002];
bool solve(vector<int>& nums, int idx, int currentSum, int sum)
{
    if(currentSum == sum)
        return true;
    if(currentSum > sum || idx >= nums.size())
        return false;

    int &ret = dp[idx][currentSum];
    if(~ret)
        return ret;

    return ret = solve(nums, idx+1, currentSum, sum) | solve(nums, idx+1, currentSum+nums[idx], sum);
}

bool canPartition(vector<int>& nums)
{
    memset(dp, -1, sizeof(dp));
    int sum = 0;
    for(int i =0;i<nums.size();++i)
        sum += nums[i];
    if(sum & 1)
        return false;
    return solve(nums, 0, 0, sum/2);
}
