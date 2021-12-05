#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[102][2];
int solve(vector<int> &nums, int idx, bool tookFirst=0)
{
    // can't take both first and last element (circular)
    if(idx >= nums.size() - tookFirst)
        return 0;

    int &ret = dp[idx][tookFirst];
    if(~ret)
        return ret;
    return ret = max(solve(nums, idx + 1, tookFirst), solve(nums, idx + 2, idx==0 | tookFirst) + nums[idx]);
}

int rob(vector<int>& nums)
{
    memset(dp, -1, sizeof(dp));
    return solve(nums, 0);
    
    // Bottom Up
    // if(nums.size() == 1)
    //     return nums[0];
    
    // int ans = 0;
    // int dp1[102];
    // memset(dp1, 0, sizeof(dp1));
    // dp1[1] = nums[0];
    // for (int i = 1; i < nums.size()-1;++i)
    // {
    //     dp1[i + 1] = max(dp1[i], dp1[i - 1] + nums[i]);
    // }
    // ans = dp1[nums.size()-1];

    // memset(dp1, 0, sizeof(dp1));
    // dp1[2] = nums[1];
    // for (int i = 2; i < nums.size();++i)
    // {
    //     dp1[i + 1] = max(dp1[i], dp1[i - 1] + nums[i]);
    // }
    // return max(ans, dp1[nums.size()]);
}

int main()
{
    vector<int> vec = {2, 3, 2};
    cout << rob(vec);
    return 0;
}