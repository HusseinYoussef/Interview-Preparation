#include <vector>

using namespace std;

int maximumUniqueSubarray(vector<int>& nums)
{
    int n = nums.size();

    int ans = 0, sum = 0;
    vector<int> freq(10004, 0);
    int l = 0, r = 0;
    while(r < n)
    {
        if(freq[nums[r]] == 0)
        {
            sum += nums[r];
            ans = max(ans, sum);
            freq[nums[r++]]++;
        }
        else
        {
            sum -= nums[l];
            freq[nums[l++]]--;
        }
    }
    return ans;
}