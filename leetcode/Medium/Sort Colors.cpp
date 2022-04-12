#include <vector>

using namespace std;

void sortColors(vector<int>& nums)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    for (int i = 0; i <= r;++i)
    {
        while((nums[i] == 0 || nums[i] == 2) && i >= l && i <= r)
        {
            if(nums[i] == 0)
                swap(nums[i], nums[l++]);
            else
                swap(nums[i], nums[r--]);
        }
    }
}