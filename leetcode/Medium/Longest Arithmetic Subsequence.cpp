#include <vector>
#include <unordered_map>

using namespace std;

int longestArithSeqLength(vector<int>& nums)
{
    int n = nums.size();

    // dp[idx][diff] -> number of times this "diff" in a subsequence ending with idx
    // vector<unordered_map<int, int>> dp(n);       // TLE
    vector<vector<int>> dp(n, vector<int>(1005, 0));
    int ans = 2;
    for (int i = 0; i < n;++i)
    {
        for (int j = i + 1; j < n;++j)
        {
            // diff is in range -500 ~ 500  -> shift to 0 ~ 1000
            int diff = nums[j] - nums[i] + 500;
            // diff = j - i, check how many this diff appeared before i (i.e. i - x and so on)
            dp[j][diff] = dp[i][diff] + 1;
            ans = max(ans, dp[j][diff] + 1);
        }
    }
    return ans;
}