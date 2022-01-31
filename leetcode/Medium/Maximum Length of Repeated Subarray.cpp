#include <vector>
#include <cstring>

using namespace std;

int n, m;
int dp[1005][1005][2];
int solve(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2, bool st)
{
    if(idx1 == n || idx2 == m)
        return 0;

    int &ret = dp[idx1][idx2][st];
    if(~ret)
        return ret;

    if(st)
    {
        if(nums1[idx1] == nums2[idx2])
            return ret = max(ret, solve(nums1, nums2, idx1 + 1, idx2 + 1, 1) + 1);
        else
            return ret = 0;
    }
    if(nums1[idx1] == nums2[idx2])
        ret = max(ret, solve(nums1, nums2, idx1 + 1, idx2 + 1, 1) + 1);
    return ret = max(ret, max(solve(nums1, nums2, idx1 + 1, idx2, 0), solve(nums1, nums2, idx1, idx2 + 1, 0)));
}

int findLength(vector<int>& nums1, vector<int>& nums2)
{
    // memset(dp, -1, sizeof(dp));
    // n = nums1.size(), m = nums2.size();
    // return solve(nums1, nums2, 0, 0, 0);

    // Bottom-Up
    int n = nums1.size(), m = nums2.size();
    int dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = n - 1; i >= 0;--i)
    {
        for (int j = m - 1; j >= 0;--j)
        {
            if(nums1[i] == nums2[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}