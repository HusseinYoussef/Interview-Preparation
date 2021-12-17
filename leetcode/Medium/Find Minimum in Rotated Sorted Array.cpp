#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums)
{
    // Find the smallest element then search in one of its sides
    int l = 0, r = nums.size()-1, mid;
    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(nums[mid] > nums[r])
            l = mid + 1;
        else
            r = mid;
    }

    return nums[l];
}