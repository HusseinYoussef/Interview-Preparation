#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int dp[1005][1005];
int solve(string &text1, string &text2, int idx1, int idx2)
{
    if(idx1 == n || idx2 == m)
        return 0;

    int &ret = dp[idx1][idx2];
    if(~ret)
        return ret;

    if(text1[idx1] == text2[idx2])
        return ret = solve(text1, text2, idx1 + 1, idx2 + 1) + 1;
    return ret = max(solve(text1, text2, idx1 + 1, idx2), solve(text1, text2, idx1, idx2 + 1));
}

int longestCommonSubsequence(string text1, string text2)
{
    memset(dp, -1, sizeof(dp));
    n = text1.size(), m = text2.size();
    return solve(text1, text2, 0, 0);

    // Bottom-Up
    // int n = text1.size(), m = text2.size();
    // int dp[1005][1005];
    // for (int i = 0; i <= n;++i)
    //     dp[i][m] = 0;
    // for (int i = 0; i <= m;++i)
    //     dp[n][i] = 0;

    // for (int idx2 = m - 1; idx2 >= 0;--idx2)
    // {
    //     for (int idx1 = n - 1; idx1 >= 0;--idx1)
    //     {
    //         if(text1[idx1] == text2[idx2])
    //         {
    //             dp[idx1][idx2] = 1 + dp[idx1 + 1][idx2 + 1];
    //         }
    //         else
    //         {
    //             dp[idx1][idx2] = max(dp[idx1 + 1][idx2], dp[idx1][idx2 + 1]);
    //         }
    //     }
    // }
    // return dp[0][0];
}