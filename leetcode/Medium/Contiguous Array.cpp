#include <vector>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int>& nums)
{
    int n = nums.size();
    unordered_map<int, int>mp;
    int ans =0, cnt = 0;
    mp[0] = -1;
    for(int i = 0;i<n;++i)
    {
        cnt = cnt + ((nums[i] == 1)? 1:-1);
        if(mp.find(cnt) != mp.end())
        {
            ans = max(ans, i - mp[cnt]);
        }
        else
            mp[cnt] = i;
    }
    return ans;
}
