#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[1005][3];
// sign = 0 neutral
// sign = 1 positive
// sign = 2 negative
int solve(vector<int>& nums, int idx, int sign)
{

    int &ret = dp[idx][sign];
    if(~ret)
        return ret;

    ret = 0;
    for(int i = idx+1;i<n;++i)
    {
        if(nums[i] - nums[idx] > 0 && (sign == 0 || sign == 2))
            ret = max(ret, solve(nums, i, 1) + 1);
        else if(nums[i] - nums[idx] < 0 && (sign == 0 || sign == 1))
            ret = max(ret, solve(nums, i, 2) + 1);
    }
    return ret;
}

int wiggleMaxLength(vector<int>& nums)
{
    n = nums.size();
    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for(int i = 0;i<n;++i)
    {
        ans = max(ans, solve(nums, i, 0) + 1);
    }
    return ans;
    
    // Bottom Up
    int n = nums.size();

    int dp[1005][3];
    memset(dp, 0, sizeof(dp));

    for(int idx = n-1;idx>=0;--idx)
    {
        for(int sign = 0;sign<3;++sign)
        {
            dp[idx][sign] = 1;
            for(int i = idx+1;i<n;++i)
            {
                if(nums[i] - nums[idx] > 0 && (sign == 0 || sign == 2))
                    dp[idx][sign] = max(dp[idx][sign], dp[i][1] + 1);
                else if(nums[i] - nums[idx] < 0 && (sign == 0 || sign == 1))
                    dp[idx][sign] = max(dp[idx][sign], dp[i][2] + 1);
            }
        }
    }
    return dp[0][0];
}
