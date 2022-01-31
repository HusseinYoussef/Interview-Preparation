#include <cstring>

using namespace std;

int mod = 1e9 + 7;
int dp[20004][6];
// a, e, i, o, u
int solve(int n, int idx, int pre)
{
    if(idx == n)
        return 1;

    int &ret = dp[idx][pre];
    if(~ret)
        return ret;

    ret = 0;
    // pre = a
    if(pre == 1)
    {
        ret = solve(n, idx + 1, 2);
    }
    else if(pre == 2)
    {
        ret = ((solve(n, idx + 1, 1) % mod) + (solve(n, idx + 1, 3) % mod)) % mod;
    }
    else if(pre == 4)
    {
        ret = ((solve(n, idx + 1, 3) % mod) + (solve(n, idx + 1, 5) % mod)) % mod;
    }
    else if(pre == 5)
    {
        ret = solve(n, idx + 1, 1);
    }
    else
    {
        for (int i = 1; i <= 5;++i)
        {
            if(pre == 3 && i == 3)
                continue;
            ret = ((ret % mod) + (solve(n, idx + 1, i) % mod)) % mod;
        }
    }
    return ret;
}

int countVowelPermutation(int n)
{
    // memset(dp, -1, sizeof(dp));
    // return solve(n, 0, 0);

    // // Bottom-Up
    int dp[20004][6];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 6;++i)
        dp[n][i] = 1;
    for (int idx = n - 1; idx >= 0;--idx)
    {
        for (int pre = 0; pre < 6;++pre)
        {
            if(pre == 1)
            {
                dp[idx][pre] = dp[idx + 1][2];
            }
            else if(pre == 2)
            {
                dp[idx][pre] = ((dp[idx + 1][1] % mod) + (dp[idx + 1][3] % mod)) % mod;
            }
            else if(pre == 4)
            {
                dp[idx][pre] = ((dp[idx + 1][3] % mod) + (dp[idx + 1][5] % mod)) % mod;
            }
            else if(pre == 5)
            {
                dp[idx][pre] = dp[idx + 1][1];
            }
            else
            {
                for (int i = 1; i <= 5;++i)
                {
                    if(pre == 3 && i == 3)
                        continue;
                    dp[idx][pre] = ((dp[idx][pre] % mod) + (dp[idx + 1][i] % mod)) % mod;
                }
            }
        }
    }
    return dp[0][0];


    // rolling - State Reduction
    // int dp[2][6];
    // memset(dp, 0, sizeof(dp));
    // for (int i = 0; i < 6;++i)
    //     dp[1][i] = 1;
    // bool roll = 0;
    // for (int idx = n - 1; idx >= 0;--idx)
    // {
    //     for (int pre = 0; pre < 6;++pre)
    //     {
    //         dp[roll][pre] = 0;
    //         if(pre == 1)
    //         {
    //             dp[roll][pre] = dp[!roll][2];
    //         }
    //         else if(pre == 2)
    //         {
    //             dp[roll][pre] = ((dp[!roll][1] % mod) + (dp[!roll][3] % mod)) % mod;
    //         }
    //         else if(pre == 4)
    //         {
    //             dp[roll][pre] = ((dp[!roll][3] % mod) + (dp[!roll][5] % mod)) % mod;
    //         }
    //         else if(pre == 5)
    //         {
    //             dp[roll][pre] = dp[!roll][1];
    //         }
    //         else
    //         {
    //             for (int i = 1; i <= 5;++i)
    //             {
    //                 if(pre == 3 && i == 3)
    //                     continue;
    //                 dp[roll][pre] = ((dp[roll][pre] % mod) + (dp[!roll][i] % mod)) % mod;
    //             }
    //         }
    //     }
    //     roll = !roll;
    // }
    // return dp[roll][0];
}