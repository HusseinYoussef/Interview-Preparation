#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums)
{
    // DP

    int ans = nums[0];
    int curMax = 1, curMin = 1;
    for (int i = 0; i < nums.size();++i)
    {
        int tmp = nums[i] * curMax;
        curMax = max(nums[i] * curMax, max(nums[i] * curMin, nums[i]));
        curMin = min(tmp, min(nums[i] * curMin, nums[i]));
        ans = max(ans, curMax);
    }
    return ans;

    // Max(prefix product, suffix product)
/*
    Here's the proof:

    Say, we have a subarray A[i : j](i != 0, j != n) and the product of elements inside is P. Take P > 0 for example: 
    if A[i] > 0 or A[j] > 0, then obviously, we should extend this subarray to include A[i] or A[j]; if both A[i] and A[j] are negative,
    then extending this subarray to include both A[i] and A[j] to get a larger product.
    Repeating this procedure and eventually we will reach the beginning or the end of A.

    What if there are zeroes in the array? Well, we can split the array into several smaller ones. 
    That's to say, when the prefix product is 0, we start over and compute prefix profuct from the current element instead.
    And this is exactly what A[i] *= (A[i - 1]) or 1 does.
*/
    // int ans = nums[0];
    // int l = 1, r = 1;
    // for (int i = 0; i < nums.size();++i)
    // {
    //     l = l ? l : 1;
    //     r = r ? r : 1;
    //     l = l * nums[i];
    //     r = r * nums[nums.size() - 1 - i];
    //     ans = max(ans, max(l, r));
    // }
    // return ans;
}

int main()
{
    vector<int> vec = {0, 2, 3};
    maxProduct(vec);
    return 0;
}