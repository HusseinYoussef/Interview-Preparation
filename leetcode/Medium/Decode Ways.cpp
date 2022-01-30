#include <iostream>
#include <cstring>

using namespace std;

int n;
int dp[105];
int solve(string &s, int idx)
{
    if(idx == n)
        return 1;

    int &ret = dp[idx];
    if(~ret)
        return ret;

    ret = 0;
    int num = 0;
    for (int i = idx; i < n;++i)
    {
        num = num * 10 + (s[i] - '0');
        if(num == 0 || num > 26)
            break;
        ret += solve(s, i + 1);
    }
    return ret;
}

int numDecodings(string s)
{
    memset(dp, -1, sizeof(dp));
    n = s.size();
    return solve(s, 0);

    // Bottom-Up
    int n = s.size();
    int dp[105];
    memset(dp, 0, sizeof(dp));
    dp[n] = 1;
    for (int idx = n - 1; idx >= 0;--idx)
    {
        int num = 0;
        for (int i = idx; i < n;++i)
        {
            num = num * 10 + (s[i] - '0');
            if(num == 0 || num > 26)
                break;
            dp[idx] += dp[i + 1];
        }
    }
    return dp[0];
}