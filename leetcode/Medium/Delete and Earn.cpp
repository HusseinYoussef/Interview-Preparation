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
    dp[n] = 0;
    dp[n-1] = nums[n-1] * freq[nums[n-1]];
    for(int i = n-2;i>=0;--i)
    {
        // take all element with value nums[i] or leave nums[i]
        dp[i] = max(nums[i] * freq[nums[i]] + dp[i + 1 + (nums[i] + 1 == nums[i + 1])], dp[i + 1]);
    }
    return dp[0];
}