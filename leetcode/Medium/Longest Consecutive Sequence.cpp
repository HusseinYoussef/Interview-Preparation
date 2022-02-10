#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums)
{
    int n = nums.size();
    unordered_map<int, bool> mp;
    for(int i =0;i<n;++i)
        mp[nums[i]] = 1;

    int ans = 0, l, r, cnt = 0;
    for(int i = 0;i<n;++i)
    {
        if(mp[nums[i]])
        {
            r = nums[i]+1;
            l = nums[i]-1;
            cnt = 1;
            while(mp[l] || mp[r])
            {
                if(mp[r])
                {
                    mp[r] = 0;
                    ++cnt;
                    ++r;
                }
                if(mp[l])
                {
                    mp[l] = 0;
                    ++cnt;
                    --l;
                }                    
            }
        }
        ans = max(ans, cnt);
    }
    return ans;
}
