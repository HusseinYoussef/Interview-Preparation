#include <vector>

using namespace std;

int deleteAndEarn(vector<int>& nums)
{
    int n = nums.size();
    vector<int> freq(10005, 0);
    for(int i = 0;i<n;++i)
        freq[nums[i]]++;
    nums.clear();
    for(int i = 0;i<10001;++i)
    {
        if(freq[i])
            nums.push_back(i);
    }
    n = nums.size();
    int dp[10004];
    dp[0] = nums[0] * freq[nums[0]];
    if(n > 1)
            dp[1] = max(dp[0], nums[1] * freq[nums[1]] + ((nums[0] + 1 == nums[1])? 0 : dp[0]));
    // dp[i] -> answer to problem starting from 0 to i (inclusive)
    for(int i = 2;i<n;++i)
    {
        dp[i] = max(dp[i-1], nums[i] * freq[nums[i]] + dp[i-1-(nums[i] - 1 == nums[i-1])]);
    }
    return dp[n-1];
}