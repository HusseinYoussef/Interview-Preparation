#include <vector>
#include <unordered_map>

using namespace std;

int findPairs(vector<int>& nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> freq;
    for(int i = 0;i<n;++i)
        ++freq[nums[i]];
    int ans = 0;
    for(int i = 0;i<n;++i)
    {
        if(k > 0 && freq[nums[i] + k] > 0)
            ++ans;
        else if(k == 0 && freq[nums[i]] > 1)
            ++ans;
        freq[nums[i]+k] = 0;   
    }
    return ans;
}
