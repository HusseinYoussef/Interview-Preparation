#include <iostream>
#include <cstring>

using namespace std;

int dp[105][105];
int solve(string &s1, string &s2, string &s3, int idx1, int idx2)
{
    if(idx1 == s1.size() && idx2 == s2.size())
        return 1;

    int &ret = dp[idx1][idx2];
    if(~ret)
        return ret;

    int idx3 = idx1 + idx2;
    ret = 0;
    if(idx1 < s1.size() && s1[idx1] == s3[idx3])
        ret |= solve(s1, s2, s3, idx1 + 1, idx2);
    if(idx2 < s2.size() && s2[idx2] == s3[idx3])
        ret |= solve(s1, s2, s3, idx1, idx2 + 1);
    return ret;
}

bool isInterleave(string s1, string s2, string s3)
{
    if(s1.size() + s2.size() != s3.size())
        return false;

    memset(dp, -1, sizeof(dp));
    return solve(s1, s2, s3, 0, 0);

    // Bottom-Up
    int dp[105][105];
    memset(dp, 0, sizeof(dp));
    dp[s1.size()][s2.size()] = 1;
    for (int idx1 = s1.size(); idx1 >= 0; --idx1)
    {
        for (int idx2 = s2.size(); idx2 >= 0; --idx2)
        {
            int idx3 = idx1 + idx2;
            if(idx1 < s1.size() && s1[idx1] == s3[idx3])
                dp[idx1][idx2] |= dp[idx1 + 1][idx2];
            if(idx2 < s2.size() && s2[idx2] == s3[idx3])
                dp[idx1][idx2] |= dp[idx1][idx2 + 1];
        }
    }
    return dp[0][0];
}