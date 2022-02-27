#include <vector>

using namespace std;

bool ok(int target, vector<int>& nums, int wsize)
{
    int i = 0;
    int sum = 0;
    for(; i<wsize;++i)
        sum += nums[i];

    if(sum >= target)
        return true;
    for(;i<nums.size();++i)
    {
        sum -= nums[i-wsize];
        sum += nums[i];
        if(sum >= target)
            return true;    
    }
    return false;
}

int minSubArrayLen(int target, vector<int>& nums)
{
    // O(N)
    int n = nums.size();
    int l = 0, r = 0;
    int sum = 0, ans = INT_MAX;
    while(l < n || r < n)
    {
        if(l < n && sum >= target)
        {
            ans = min(ans, r-l);
            sum -= nums[l++];
        }
        else if(r < n)
            sum += nums[r++];
        else
            break;
    }
    if(ans == INT_MAX)
        return 0;
    return ans;

    // O(N log N)
    int n = nums.size();
    // (l, r) open intervals
    int l = 0, r = n+1, mid;
    while(r-l > 1)
    {
        mid = l + (r-l)/2;
        if(ok(target, nums, mid))
            r = mid;
        else
            l = mid;
    }
    if(r > n)
        return 0;
    return r;
}
