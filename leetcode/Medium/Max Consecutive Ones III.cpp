#include <vector>

using namespace std;

int longestOnes(vector<int>& nums, int k)
{
    int n = nums.size();

    int l = 0, ans = 0;
    for(int i = 0;i<n;)
    {
        if(nums[i] == 1)
            ++i;
        else
        {
            if(k)
            {
                ++i;
                --k;
            }
            else
            {
                if(nums[l] == 0)
                    ++k;
                ++l;
            }
        }
        ans = max(ans, i-l);
    }
    return ans;
}
