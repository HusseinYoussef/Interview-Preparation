#include <iostream>
#include <cstring>

using namespace std;

int dp[105];
int solve(string &s, int idx)
{
    if(idx == s.size())
        return 1;

    int &ret = dp[idx];
    if(~ret)
        return ret;

    ret = 0;
    int num = 0;
    for (int i = idx; i < s.size();++i)
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
    return solve(s, 0);
}