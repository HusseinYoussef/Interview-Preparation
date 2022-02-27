#include <vector>
#include <cstring>

using namespace std;

int dp[205][10005];
int solve(vector<int>& nums, int idx, int left)
{
    if(left == 0)
        return 1;
    if(idx == nums.size())
        return 0;

    int &ret = dp[idx][left];
    if(~ret)
        return ret;

    ret = 0;
    if(nums[idx] <= left)
        ret = solve(nums, idx+1, left-nums[idx]);
    if(ret)
        return ret;
    return ret |= solve(nums, idx+1, left);
}

bool canPartition(vector<int>& nums)
{
    int n = nums.size();
    int sum = 0;
    for(int i =0;i<n;++i)
        sum+=nums[i];
    if(sum & 1)
        return false;

    memset(dp, -1, sizeof(dp));
    return solve(nums, 0, sum/2);

    // Bottom Up
    int dp[205][10005];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<205;++i)
        dp[i][0] = 1;

    for(int left = 1; left<= sum/2;++left)
    {
        for(int idx = n-1;idx>=0;--idx)
        {
            if(nums[idx] <= left)
                dp[idx][left] = dp[idx+1][left-nums[idx]];
            dp[idx][left] |= dp[idx+1][left];
        }
    }
    return dp[0][sum/2];
}
