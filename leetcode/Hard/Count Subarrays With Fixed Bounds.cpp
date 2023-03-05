#include <iostream>
using namespace std;

long long countSubarrays(vector<int>& nums, int minK, int maxK)
{
    // O(N) time, O(1) Space
    int n = nums.size();
    int leftBoundry = -1;
    int lastMin = -1, lastMax = -1;
    long long ans = 0;
    for(int i =0;i<n;++i)
    {
        if (nums[i] >= minK && nums[i] <= maxK)
        {
            if (nums[i] == minK)
                lastMin = i;
            if (nums[i] == maxK)
                lastMax = i;

            ans += max(0, min(lastMin, lastMax) - leftBoundry);
        }
        else
        {
            leftBoundry = i;
            lastMin = lastMax = -1; // reset pointers
        }
    }
    return ans;
}
