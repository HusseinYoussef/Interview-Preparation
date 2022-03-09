#include <vector>
#include <algorithm>

using namespace std;

int n, subset_sum, K;
bool rec(vector<int>& nums, int vis, int sum, int ks, int idx)
{
    if(ks == 1)
        return true;

    if(sum == subset_sum)
        return rec(nums, vis, 0, ks - 1, K - ks + 1);

    for (int i = idx; i < n;++i)
    {
        if(vis & (1 << i) || nums[i] + sum > subset_sum)
            continue;

        vis |= 1 << i;
        if(rec(nums, vis, sum+nums[i], ks, i+1))
            return true;
        vis &= ~(1 << i);
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k)
{
    n = nums.size(), K = k;
    int sum = 0;
    for (int i = 0; i < n;++i)
        sum += nums[i];
    
    if(sum % k != 0)
        return false;

    subset_sum = sum / k;
    sort(nums.begin(), nums.end());
    return rec(nums, 0, 0, k, 0);
}