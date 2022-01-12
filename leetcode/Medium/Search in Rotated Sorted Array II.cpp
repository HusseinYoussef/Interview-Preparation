#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target)
{
    // if there are duplicates, the same number may appear at both ends so we can't find the middle that splits the two arrays
    // get rid of duplicates at both ends, then it is the normal 'Search in rotated array'
    // 5 5 5 5 6 7 7 7 1 2 3 4 5, first sorted array = 5 5 5 6 7 7 7, second sorted array 1 2 3 4
    // O(N) Worst Case, O(Log n) best case
    int n = nums.size();
    int l = 0, r = n - 1, mid;
    while(l <= r && nums[l] == nums[r])
    {
        if(nums[l] == target)
            return true;
        ++l, --r;
    }
    if(r < l)
        return false;
    int st = l, end = r;
    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(nums[mid] <= nums[r])
            r = mid;
        else
            l = mid + 1;
    }
    int start = l;
    l = st, r = end;
    if(target <= nums[r])
        l = start;
    else
        r = start - 1;
    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(nums[mid] == target)
            return true;
        if(nums[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return nums[l] == target;
}