#include <vector>
#include <climits>

using namespace std;

int maxSubarraySumCircular(vector<int>& nums)
{
    // 2 Cases:
    // Case 1: Max subarray in the middle (not split across start and end) which is solved using normal kadane's
    // Case 2: Max subarray is split across prefix and suffix >>>>.....>>>>> since max subarray that is splitted
    // this is equal to find min subarray in the middle then subtract it from total sum;
    int n = nums.size();
    int total = 0, curMx = 0, mxSum = INT_MIN, curMn = 0, mnSum = INT_MAX;
    for (int i = 0; i < n;++i)
    {
        curMx = max(curMx + nums[i], nums[i]);
        mxSum = max(mxSum, curMx);
        curMn = min(curMn + nums[i], nums[i]);
        mnSum = min(mnSum, curMn);
        total += nums[i];
    }
    if(mxSum > 0)
        return max(mxSum, total - mnSum);
    return mxSum;
}