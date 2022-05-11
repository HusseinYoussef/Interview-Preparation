#include <vector>

using namespace std;

int totalHammingDistance(vector<int>& nums)
{
    int n = nums.size();
    int ans = 0;
    for (int j = 0; j < 32;++j)
    {
        // how many 1's appear in each bit position
        int cnt = 0;
        for (int i = 0; i < n;++i)
        {
            cnt += (nums[i] & (1 << j)) != 0;
        }
        ans += cnt * (n - cnt);  // number of 1's  *  number of 0's
    }
    return ans;
}