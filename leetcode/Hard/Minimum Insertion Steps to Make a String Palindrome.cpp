#include <iostream>
#include <cstring>

using namespace std;

int n;
int dp[502][502];
int solve(string &s, int l, int r)
{
    if(r == l)
        return 1;
    if(r < l)
        return 0;

    int &ret = dp[l][r];
    if(~ret)
        return ret;
    
    if(s[l] == s[r])
        return ret = solve(s, l + 1, r - 1) + 2;

    return ret = max(solve(s, l + 1, r), solve(s, l, r - 1));
}

int minInsertions(string s)
{
    n = s.size();
    memset(dp, -1, sizeof(dp));
    return n - solve(s, 0, n - 1);

    // Bottom Up
    int n = s.size();
    int dp[502][502];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 502;++i)
        dp[i][i] = 1;

    for (int l = n - 2; l >= 0;--l)
    {
        for (int r = l + 1; r < n;++r)
        {
            if(s[l] == s[r])
                dp[l][r] = dp[l + 1][r - 1] + 2;
            else
                dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
        }
    }
    return n - dp[0][n - 1];

    // rolling O(N) Space
    int n = s.size();
    int dp[2][502];
    memset(dp, 0, sizeof(dp));

    bool roll = 0;
    for (int l = n - 1; l >= 0;--l)
    {
        for (int r = l; r < n;++r)
        {
            if(l == r)
            {
                dp[roll][r] = 1;
                continue;
            }
            if(s[l] == s[r])
                dp[roll][r] = dp[!roll][r - 1] + 2;
            else
                dp[roll][r] = max(dp[!roll][r], dp[roll][r - 1]);
        }
        roll = !roll;
    }
    return n - dp[!roll][n - 1];
}