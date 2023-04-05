#include <vector>

using namespace std;

int minimizeArrayValue(vector<int>& nums)
{
    int n = nums.size();

    long long prefixSum = nums[0];
    long long ans = nums[0];
    for(int i = 1;i<n;++i)
    {
        prefixSum += nums[i];
        long long dist = ceil(prefixSum * 1.0 / (i+1));

        if (dist > nums[i])
            continue;

        ans = max(ans, dist);
    }
    return ans;
}
