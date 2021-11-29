#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums)
{
    int l = 0, r = nums.size() - 1;
    while (l<r)
    {
        if((nums[l] & 1) && !(nums[r] & 1))
        {
            swap(nums[l], nums[r]);
        }
        l += !(nums[l] & 1);
        r -= nums[r] & 1;
    }
    return nums;
}