#include <iostream>
#include <cstring>

using namespace std;

int dp[1002][1002];
int suffix1[1002];
int suffix2[1002];
int solve(string &word1, string &word2, int idx1, int idx2)
{
    if(idx1 == word1.size() || idx2 == word2.size())
        return suffix1[idx1] + suffix2[idx2];

    int &ret = dp[idx1][idx2];
    if(~ret)
        return ret;
    
    if(word1[idx1] == word2[idx2])
        return ret = solve(word1, word2, idx1 + 1, idx2 + 1);

    return ret = min(solve(word1, word2, idx1 + 1, idx2) + (int)word1[idx1], solve(word1, word2, idx1, idx2 + 1) + (int)word2[idx2]);
}

int minimumDeleteSum(string s1, string s2)
{
    int suffix1[1002];
    int suffix2[1002];
    suffix1[s1.size()] = suffix2[s2.size()] = 0;
    for (int i = s1.size() - 1; i >= 0;--i)
        suffix1[i] = (int)s1[i] + suffix1[i + 1];
    for (int i = s2.size() - 1; i >= 0;--i)
        suffix2[i] = (int)s2[i] + suffix2[i + 1];

    memset(dp, -1, sizeof(dp));
    return solve(s1, s2, 0, 0);

    int dp[1002][1002];
    for (int i = 0; i < 1002;++i)
    {
        dp[i][s2.size()] = suffix1[i];
        dp[s1.size()][i] = suffix2[i];
    }

    for (int idx1 = s1.size() - 1; idx1 >= 0;--idx1)
    {
        for (int idx2 = s2.size() - 1; idx2 >= 0;--idx2)
        {
            if(s1[idx1] == s2[idx2])
                dp[idx1][idx2] = dp[idx1 + 1][idx2 + 1];
            else
                dp[idx1][idx2] = min(dp[idx1 + 1][idx2] + (int)s1[idx1], dp[idx1][idx2 + 1] + (int)s2[idx2]);
        }
    }
    return dp[0][0];
}