#include <cstring>

using namespace std;

int mod = 1e9 + 7;
int dp[1005][2];
// to fill column i
// if no preGap: put a vertical domino from (i-1) or 2 horizontal dominos from (i-2) or 1 tromino from (i-1) with a gap (2 possible trominos)
// if there is a gap: put one horizontal domino from (i-1) with a gap or 1 tromino;
int solve(int n, int idx, bool preGap)
{
    if(idx > n)
        return 0;
    if(idx == n)        // valid only if there is no Gaps
        return preGap == 0;

    int &ret = dp[idx][preGap];
    if(~ret)
        return ret;

    ret = 0;
    // 1 horizontal, 1 tromino
    if(preGap)
        return ret = ((solve(n, idx + 1, 1) % mod) + (solve(n, idx + 1, 0) % mod)) % mod;
    // 1 vertical, 2 horizontal, 1 tromino (2 possible trominos)
    return ret = (((solve(n, idx + 1, 0) % mod) + (solve(n, idx + 2, 0) % mod)) % mod + (2 * solve(n, idx + 2, 1) % mod)) % mod;
}

int numTilings(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(n, 0, 0);

    // Bottom-Up
    int dp[1005][2];
    memset(dp, 0, sizeof(dp));
    dp[n][0] = 1;
    for (int idx = n - 1; idx >= 0;--idx)
    {
        dp[idx][0] = (((dp[idx + 1][0] % mod) + (dp[idx + 2][0]) % mod) % mod + (2 * dp[idx + 2][1] % mod)) % mod;
        dp[idx][1] = ((dp[idx + 1][1] % mod) + (dp[idx + 1][0] % mod)) % mod;
    }
    return dp[0][0];
}