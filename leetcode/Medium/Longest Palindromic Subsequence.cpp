#include <iostream>
#include <cstring>

using namespace std;

int n;
int dp[1005][1005];
int solve(string &s, int l, int r)
{
    if(r < l)
        return 0;

    int &ret = dp[l][r];
    if(~ret)
        return ret;
    
    if(s[l] == s[r])
        return ret = solve(s, l + 1, r - 1) + ((l == r) ? 1 : 2);
    return ret = max(solve(s, l + 1, r), solve(s, l, r - 1));
}

int longestPalindromeSubseq(string s)
{
    n = s.size();
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, n - 1);

    // Bottom Up
    int n = s.size();
    int dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n;++i)
        dp[i][i] = 1;
    for (int l = n - 1; l >= 0; --l)
    {
        for (int r = l + 1; r < n; ++r)
        {
            if(s[l] == s[r])
                dp[l][r] = 2 + dp[l + 1][r - 1];
            else
                dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
        }
    }
    return dp[0][n - 1];
}