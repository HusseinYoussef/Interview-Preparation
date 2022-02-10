#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    int n = nums.size();
    // map of prefixes
    unordered_map<int, int>mp;
    int prefix = 0, ans = 0;
    for(int i = 0;i<n;++i)
    {
        prefix += nums[i];
        if(prefix == k)
            ++ans;
        // check if a prefix with total = sum-k
        // if here we have 'sum' and we had 'sum - k' before
        // then there is subarray inbetween with sum = k
        // X>>>>>Y, if Y-K = X then between X and Y = K
        if(mp[prefix-k])
            ans += mp[prefix-k];
        ++mp[prefix];
    }
    return ans;
}
