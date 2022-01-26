#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    int n = nums.size();
    // need first T
    int l = 0, r = n-1, mid;
    while(l < r)
    {
        mid = l + (r-l)/2;
        if(nums[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }
    if(l >= n || nums[l] != target)
        return {-1, -1};

    int tmp = l;
    // need last F
    l = -1, r = n;
    while(r - l > 1)
    {
        mid = l + (r-l)/2;
        if(nums[mid] > target)
            r = mid;
        else
            l = mid;
    }
    return {tmp, l};
}
