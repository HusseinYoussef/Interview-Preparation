#include <vector>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    for(int i = n-1;i>=0;--i)
    {
        // right most bit indicates val is even or odd, rest of bits resemble count of evens
        if (nums[i] & 1)
        {
            nums[i] = (cnt << 1) | 1;
            cnt = 0;
        }
        else
        {
            nums[i] = (cnt << 1);
            ++cnt;
        }
    }

    int ans = 0;
    int l = 0, r = -1;
    while (r < n)
    {
        if (k == 0)
        {
            ans += 1 + (nums[r] >> 1);
            k += nums[l++] & 1;
        }
        else
        {
            ++r;
            if(r == n)
                break;
            k -= nums[r] & 1;
        }
    }
    return ans;        
}
