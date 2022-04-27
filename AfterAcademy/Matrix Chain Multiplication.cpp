#include <vector>
#include <cstring>

using namespace std;

// Same problem as Burst Balloons in leetcode ~ DP Reverse Thinking
int n;
int dp[502][502];
int solve(vector<int>& arr, int l, int r)
{
    if(r - l <= 1)
        return 0;

    int &ret = dp[l][r];
    if(~ret)
        return ret;

    ret = 1e8;
    for (int i = l + 1; i < r;++i)
    {
        int left = solve(arr, l, i);
        int right = solve(arr, i, r);
        ret = min(ret, left + right + arr[l] * arr[r] * arr[i]);
    }
    return ret;
}

int matrixChainMultiplication(vector<int>& arr)
{
    n = arr.size();
    memset(dp, -1, sizeof(dp));
    return solve(arr, 0, n - 1);

    // Bottom Up
    int n = arr.size();
    int dp[502][502];
    memset(dp, 0, sizeof(dp));
    for (int l = n - 3; l >= 0; --l)
    {
        for (int r = l + 2; r < n; ++r)
        {
            dp[l][r] = 1e8;
            for (int i = l + 1; i < r;++i)
            {
                int left = dp[l][i];
                int right = dp[i][r];
                dp[l][r] = min(dp[l][r], left + right + arr[l] * arr[r] * arr[i]);
            }
        }
    }
    return dp[0][n - 1];
}