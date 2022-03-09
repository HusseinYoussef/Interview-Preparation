#include <vector>
#include <unordered_map>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    int prefix = 0;
    mp[0] = -1;
    for(int i = 0;i<n;++i)
    {
        // (a+(n*x))%x is same as (a%x)
        prefix += nums[i];
        prefix %= k;
        if(mp.find(prefix) != mp.end() && i - mp[prefix] > 1)
            return true;
        if(mp.find(prefix) == mp.end())
            mp[prefix] = i;
    }
    return false;
}
