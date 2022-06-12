#include <vector>
#include <unordered_map>

using namespace std;

int maximumUniqueSubarray(vector<int>& nums)
{
    int n = nums.size();

    int ans = 0, sum = 0;
    unordered_map<int, int> freq;
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