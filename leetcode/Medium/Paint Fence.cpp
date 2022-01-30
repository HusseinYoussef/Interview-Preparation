#include <vector>
#include <cstring>

using namespace std;

int dp[22][3];
int solve(int n, int k, int idx, int consecutive, int preColor)
{
    if(idx == n)
        return 1;

    int &ret = dp[idx][consecutive];
    if(~ret)
        return ret;

    ret = 0;
    for (int c = 0; c < k;++c)
    {
        if(c != preColor || consecutive < 2)
        {
            ret += solve(n, k, idx + 1, (c == preColor) ? 2 : 1, c);
        }
    }
    return ret;
}

int numWays(int n, int k)
{
    memset(dp, -1, sizeof(dp));
    return solve(n, k, 0, 0, -1);

    // Bottom-Up
    // dp[i] = (dp[i-1] + dp[i-2]) * (k-1)
    // Can be reduced to 2 variables
    if(n == 1)
        return k;
    int pre1 = k * k;
    int pre2 = k;
    for (int i = 3; i <= n;++i)
    {
        int tmp = (pre1 + pre2) * (k - 1);
        pre2 = pre1;
        pre1 = tmp;
    }
    return pre1;
}