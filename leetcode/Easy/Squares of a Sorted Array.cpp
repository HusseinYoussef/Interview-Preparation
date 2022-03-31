#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> sortedSquares(vector<int>& nums)
{
    // Make use of the sorting
    // O(n) Time, O(n) Space
    int n = nums.size();
    vector<int> ans(n);
    int l = 0, r = n - 1;
    int idx = n - 1;
    while(l <= r)
    {
        // one of the two ends (l, r) will have the next value (biggest value) to store in ans
        if(abs(nums[r]) >= abs(nums[l]))
        {
            ans[idx] = nums[r] * nums[r];
            --r;
        }
        else
        {
            ans[idx] = nums[l] * nums[l];
            ++l;
        }
        --idx;
    }
    return ans;
}
