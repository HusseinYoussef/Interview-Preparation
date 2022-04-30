#include <vector>

using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot)
{
    int n = nums.size();
    int higher = 0;
    for (int i = 0; i < n;++i)
        higher += nums[i] > pivot;

    vector<int> ans(n, pivot);
    int l = 0, r = n - higher;
    for (int i = 0; i < n;++i)
    {
        if(nums[i] < pivot)
            ans[l++] = nums[i];
        else if(nums[i] > pivot)
            ans[r++] = nums[i];
    }
    return ans;
}