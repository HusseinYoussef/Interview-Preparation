#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums)
{
    int l = 0, r = nums.size() - 1;
    int idx = 0;
    while(l < nums.size() && r >= 0 && idx <= r)
    {
        while(l < nums.size() && nums[l] == 0)
            ++l;
        while(r >= 0 && nums[r] == 2)
            --r;
        if(l > nums.size() || r < 0)
            break;
        if(nums[idx] == 0 && idx >= l)
        {
            swap(nums[idx], nums[l++]);
            continue;
        }
        else if(nums[idx] == 2)
        {
            swap(nums[idx], nums[r--]);
            continue;
        }
        ++idx;
    }
}