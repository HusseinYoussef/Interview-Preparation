#include <vector>

using namespace std;

int minOperations(vector<int>& nums, int x)
{
    // find largest window with sum = total - x
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n;++i)
        sum += nums[i];

    if(x > sum)
        return -1;
    if(x == sum)
        return n;

    int target = sum - x;
    sum = 0;
    int ans = -1;
    int l = 0, r = 0;
    while(l < n || r < n)
    {
        if(sum <= target)
        {
            if(r == n)
                break;
            sum += nums[r++];
        }
        else
        {
            sum -= nums[l++];
        }
        if(sum == target)
            ans = max(ans, r-l);
    }
    if(ans == -1)
        return -1;
    return n - ans;
}