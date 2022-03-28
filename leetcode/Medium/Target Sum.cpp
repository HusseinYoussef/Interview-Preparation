#include <vector>
#include <map>

using namespace std;

int n;
int ans = 0;
// backtracking O(2^n)
void rec(vector<int>& nums, int idx, int sum)
{
    if(idx == nums.size())
    {
        ans += sum == 0;
        return;
    }
    rec(nums, idx + 1, sum - nums[idx]);
    rec(nums, idx + 1, sum - nums[idx]);
}

// DP Top-Down O(n*target)
map<pair<int, int>, int> dp;
int solve(vector<int>& nums, int idx, int sum)
{
    if(idx == n)
        return sum == 0;
    
    if(dp.find({idx, sum}) != dp.end())
        return dp[{idx, sum}];

    dp[{idx, sum}] = solve(nums, idx + 1, sum - nums[idx]) + solve(nums, idx + 1, sum + nums[idx]);
}

int findTargetSumWays(vector<int>& nums, int target)
{
    n = nums.size();
    return solve(nums, 0, target);

    // DP Bottom Up - TLE
    // map<pair<int, int>, int> dp;
    // // Base Case
    // dp[{n, 0}] = 1; // dp[{n, any_thing}] = 0

    // for (int idx = n - 1; idx >= 0;--idx)
    // {
    //     for (int sum = -1000; sum <= 1000;++sum)
    //     {
    //         dp[{idx, sum}] = dp[{idx + 1, sum - nums[idx]}] + dp[{idx + 1, sum + nums[idx]}];
    //     }
    // }
    // return dp[{0, target}];
}