#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums)
{
    int n = nums.size();
    int l = 0, r = n - 1, mid;
    while(l < r)
    {
        mid = l + (r - l) / 2;
        // find element that has odd numbers before it inclusive
        // FFFFTTTTTT
        if((mid + 1 + (mid + 1 < n && nums[mid] == nums[mid+1])) & 1)
            r = mid;
        else
            l = mid + 1;
    }
    return nums[r];
}