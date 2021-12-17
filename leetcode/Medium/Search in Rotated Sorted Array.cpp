#include <iostream>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target)
{
    if(nums.size() == 0)
        return -1;
    
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

    int start = l;
    l = 0, r = nums.size() - 1;
    // pick a side
    if(target >= nums[start] && target <= nums[r])
        l = start;
    else
        r = start;

    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    if(nums[l] != target)
        return -1;
    return l;
}