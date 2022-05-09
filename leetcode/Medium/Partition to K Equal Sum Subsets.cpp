#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> dp;
bool solve(vector<int>& nums, int idx, int msk, int leftSets, int subsetSum, int target)
{
    if(leftSets == 1)
        return true;
    
    if(dp.find(msk) != dp.end())
        return dp[msk];

    if(subsetSum == target)
        return dp[msk] = solve(nums, 0, msk, leftSets - 1, 0, target);
    
    for (int i = idx; i < nums.size();++i)
    {
        if((msk & (1<<i)) || nums[i] + subsetSum > target)
            continue;

        if(solve(nums, i + 1, msk | (1 << i), leftSets, subsetSum + nums[i], target))
            return dp[msk] = true;
    }
    return dp[msk] = false;
}

bool canPartitionKSubsets(vector<int>& nums, int k)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n;++i)
        sum += nums[i];
    
    if(sum % k != 0)
        return false;
    
    sort(nums.begin(), nums.end(), greater<int>());
    return solve(nums, 0, 0, k, 0, sum / k);
}