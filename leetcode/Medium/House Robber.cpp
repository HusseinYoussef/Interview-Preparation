#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[102];
int solve(vector<int> &nums, int idx)
{
    if(idx >= nums.size())
        return 0;

    int &ret = dp[idx];
    if(~ret)
        return ret;
    return ret = max(solve(nums, idx + 1), solve(nums, idx + 2) + nums[idx]);
}

int rob(vector<int>& nums)
{
    memset(dp, -1, sizeof(dp));
    return solve(nums, 0);

    // iterative - Bottom Up

    // memset(dp, 0, sizeof(dp));
    // dp[0] = 0;
    // dp[1] = nums[0];
    // for (int i = 1; i < nums.size();++i)
    // {
    //     dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
    // }
    // return dp[nums.size()];
}

int main()
{
    vector<int> vec = {2, 7, 9, 3, 1};
    cout << rob(vec);
    return 0;
}