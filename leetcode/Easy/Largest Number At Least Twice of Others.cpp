#include <iostream>
#include <vector>

using namespace std;

int dominantIndex(vector<int>& nums)
{
    int mx1 = -1 ,mx2 = -1, idx = -1;
    for(int i =0;i<nums.size();++i)
    {
        if(nums[i] > mx1)
        {
            mx2 = mx1;
            mx1 = nums[i];
            idx = i;
        }
        else if(nums[i] > mx2)
            mx2 = nums[i];
    }
    if(mx2 == -1 || mx1 >= mx2*2)
        return idx;
    return -1;
}
