#include <cstring>

using namespace std;

int dp[16][1 << 15];
int solve(int idx, int msk, int n)
{
    if(idx == n)
        return 1;

    int &ret = dp[idx][msk];
    if(~ret)
        return ret;

    ret = 0;
    for (int i = 1; i <= n;++i)
    {
        if((msk & (1 << (i-1))) == 0 && ((i % (idx+1)) == 0 || ((idx+1) % i) == 0))
        {
            msk |= 1 << (i-1);
            ret += solve(idx + 1, msk, n);
            msk ^= 1 << (i-1);
        }
    }
    return ret;
}

int countArrangement(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, n);

    // Bottom Up
    int dp[16][1 << 15];
    memset(dp, 0, sizeof(dp));
    int tmp = 1 << 15;
    for (int i = 0; i < tmp;++i)
        dp[n][i] = 1;

    for (int idx = n - 1; idx >= 0;--idx)
    {
        for (int msk = tmp - 1; msk >= 0;--msk)
        {
            for (int i = 1; i <= n;++i)
            {
                if((msk & (1 << (i-1))) == 0 && ((i % (idx+1)) == 0 || ((idx+1) % i) == 0))
                {
                    dp[idx][msk] += dp[idx + 1][msk | (1 << (i - 1))];
                }
            }
        }
    }
    return dp[0][0];
}