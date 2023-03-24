#include <vector>
#include <unordered_map>

using namespace std;

int getCountAtMostK(vector<int>& nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> freq;

    int l = 0, r = 0;
    int ans = 0;
    for(;r < n; ++r)
    {
        if (++freq[nums[r]] == 1)
            --k;

        while (k < 0)
        {
            if(--freq[nums[l]] == 0)
                ++k;
            ++l;
        }
        ans += r - l + 1;
    }
    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k)
{
    // exactly (k) = atMost(k) - atMost(K-1)
    return getCountAtMostK(nums, k) - getCountAtMostK(nums, k-1);
}
