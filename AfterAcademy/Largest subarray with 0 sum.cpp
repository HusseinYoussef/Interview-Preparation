#include <vector>
#include <unordered_map>

using namespace std;

int largestSubarrayZero(vector<int>& arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int prefix = 0, ans = 0;
    mp[0] = -1;
    for (int i = 0; i < n;++i)
    {
        prefix += arr[i];
        if(mp.find(prefix) == mp.end())
            mp[prefix] = i;
        else
            ans = max(ans, i - mp[prefix]);
    }
    return ans;
}