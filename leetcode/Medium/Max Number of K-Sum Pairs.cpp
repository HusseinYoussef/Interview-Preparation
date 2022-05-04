#include <vector>
#include <unordered_map>

using namespace std;

int maxOperations(vector<int>& nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    int ans = 0;
    for(int i = 0;i<n;++i)
    {
        ++mp[nums[i]];
        if(mp[k-nums[i]] && nums[i] != k - nums[i])
        {
            ++ans;
            --mp[nums[i]];
            --mp[k-nums[i]];
        }
        else if(mp[nums[i]] > 1 && nums[i] == k - nums[i])
        {
            ++ans;
            mp[nums[i]] -= 2;
        }
    }
    return ans;
}
