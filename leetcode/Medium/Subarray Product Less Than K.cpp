#include <vector>

using namespace std;

/* another solution ~ O(N)
int countSubarrays(int l, int i, int preWinEnd)
{
    // window [l, i)
    int len = i - l;
    int subarrays = (1 + len) * len / 2;
    int overlapSubarrays = 0;
    if(l <= preWinEnd)
    {
        int overlapLen = preWinEnd - l + 1;
        overlapSubarrays = (1 + overlapLen) * overlapLen / 2;
    }
    return subarrays - overlapSubarrays;
}

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    int n = nums.size();
    int ans = 0;

    int l = 0;
    int preWinEnd = -1;
    int product = 1;
    int i = 0;
    for (i = 0; i < n;)
    {
        // start a new problem
        if(nums[i] >= k)
        {
            ans += countSubarrays(l, i, preWinEnd);
            ++i;
            l = i;
            product = 1;
            preWinEnd = -1;
            continue;
        }
        if(nums[i] * product >= k)
        {
            ans += countSubarrays(l, i, preWinEnd);
            preWinEnd = i - 1;
            while(product * nums[i] >= k && l < i)
            {
                product /= nums[l++];
            }
        }
        else
        {
            product *= nums[i++];
        }
    }
    ans += countSubarrays(l, i, preWinEnd);
    return ans;
}
*/
int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    int n = nums.size();
    int ans = 0;

    int l = 0, product = 1;
    for (int i = 0; i < n;++i)
    {
        product *= nums[i];
        while (product >= k)
            product /= nums[l++];

        ans += i - l + 1;
    }
    return ans;
}