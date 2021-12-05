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
}

int main()
{
    vector<int> vec = {200, 3, 140, 20, 10};
    cout << rob(vec);
    return 0;
}