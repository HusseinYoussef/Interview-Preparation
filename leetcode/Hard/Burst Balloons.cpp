#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[302][302];
int solve(vector<int>& arr, int l, int r)
{
    if(r - l <= 1)
        return 0;

    int &ret = dp[l][r];
    if(~ret)
        return ret;

    for (int i = l + 1; i < r;++i)
    {
        int left = solve(arr, l, i);
        int right = solve(arr, i, r);
        ret = max(ret, left + right + arr[l] * arr[r] * arr[i]);
    }
    return ret;
}

int maxCoins(vector<int>& nums)
{
    n = nums.size();
    memset(dp, -1, sizeof(dp));
    vector<int> arr(n + 2);
    arr[0] = arr[n + 1] = 1;
    for (int i = 0; i < n;++i)
        arr[i + 1] = nums[i];
    return solve(arr, 0, n + 1);

    // Bottom Up
    int n = nums.size();
    int dp[302][302];
    memset(dp, 0, sizeof(dp));
    vector<int> arr(n + 2);
    arr[0] = arr[n + 1] = 1;
    for (int i = 0; i < n;++i)
        arr[i + 1] = nums[i];

    for (int l = n - 1; l >= 0;--l)
    {
        for (int r = l + 2; r <= n+1;++r)
        {
            for (int i = l + 1; i < r;++i)
            {
                int left = dp[l][i];
                int right = dp[i][r];
                dp[l][r] = max(dp[l][r], left + right + arr[l] * arr[r] * arr[i]);
            }
        }
    }
    return dp[0][n + 1];
}