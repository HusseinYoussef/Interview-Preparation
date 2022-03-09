#include <vector>

using namespace std;

int numberOfArithmeticSlices(vector<int>& nums)
{
    int n = nums.size();
    if(n < 3)
        return 0;

    // O(N) Space
    
    int dp[5005];
    dp[3] = 1;
    for(int i = 4;i<=n;++i)
    {
        dp[i] = dp[i-1] + (i-3) + 1;
    }

    int diff = nums[1] - nums[0];
    int ans = 0, cnt = 2;
    for(int i = 2;i<n;++i)
    {
        if(nums[i] - nums[i-1] == diff)
            ++cnt;
        if(nums[i] - nums[i-1] != diff || i == n-1)
        {
            if(cnt >= 3)
                ans += dp[cnt];
            cnt = 2;
            diff = nums[i] - nums[i-1];
        }
    }
    return ans;

    // O(1) Space
    int n = nums.size();
    if(n < 3)
        return 0;

    int diff = nums[1] - nums[0];
    int ans = 0, cnt = 2, lst = 0;
    for(int i = 2;i<n;++i)
    {
        if(nums[i] - nums[i-1] == diff)
        {
            ++cnt;
            lst = lst + (cnt-3) + 1;
        }
        if(nums[i] - nums[i-1] != diff || i == n-1)
        {
            if(cnt >= 3)
                ans += lst;
            cnt = 2;
            diff = nums[i] - nums[i-1];
            lst = 0;
        }
    }
    return ans;
}
