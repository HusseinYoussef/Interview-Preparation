#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums)
{
    int n = nums.size();
    int l = 0, r = n-1, mid, nxt, pre;
    while(l < r)
    {
        mid = l + (r-l)/2;
        nxt = (mid+1 < n)? nums[mid+1]:INT_MIN;
        pre = (mid-1 >= 0)? nums[mid-1]:INT_MIN;
        if(nums[mid] > nxt && nums[mid] > pre)
            return mid;
        if(nums[mid] < nxt)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
