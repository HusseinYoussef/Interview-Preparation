#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[10004];
int solve(vector<int>& nums, vector<int> &freq, int idx)
{
    if(idx == n-1)
        return nums[idx] * freq[nums[idx]];

    if(idx >= n)
        return 0;

    int &ret = dp[idx];
    if(~ret)
        return ret;

    return ret = max(solve(nums, freq, idx+1), solve(nums, freq, (nums[idx+1] == nums[idx]+1)? idx+2: idx+1) + nums[idx] * freq[nums[idx]]);
}

int deleteAndEarn(vector<int>& nums)
{
    n = nums.size();
    vector<int> freq(10004, 0);
    for(int i = 0;i<n;++i)
        ++freq[nums[i]];

    nums.clear();
    for(int i = 1;i<10004;++i)
    {
        if(freq[i])
            nums.push_back(i);
    }

    n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(nums, freq, 0);

    // Bottom Up
    int n = nums.size();
    vector<int> freq(10004, 0);
    for(int i = 0;i<n;++i)
        ++freq[nums[i]];

    nums.clear();
    for(int i = 1;i<10004;++i)
    {
        if(freq[i])
            nums.push_back(i);
    }

    n = nums.size();

    int dp[10004];
    memset(dp, 0, sizeof(dp));
    dp[n-1] = nums[n-1] * freq[nums[n-1]];
    for(int idx = n-2;idx>=0;--idx)
    {
        dp[idx] = max(dp[idx+1], dp[(nums[idx+1] == nums[idx]+1)? idx+2: idx+1] + nums[idx] * freq[nums[idx]]);
    }
    return dp[0];
}
