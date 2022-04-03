#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int dp[505][505];
int solve(string &word1, string &word2, int idx1, int idx2)
{
    if(idx1 == n && idx2 == m)
        return 0;
    
    // if w1 finishes first, then we must add the remaining chars to w1.
    // Similarly, if w2 finishes first, then we must delete the remaining chars from w1
    // so number of operations left that must be done = number of remaining chars (to be added or deleted in word1)
    if(idx1 == n || idx2 == m)
        return n - idx1 + m - idx2;

    int &ret = dp[idx1][idx2];
    if(~ret)
        return ret;

    if(word1[idx1] == word2[idx2])
        return ret = solve(word1, word2, idx1 + 1, idx2 + 1);
    
    // Add, Delete, Replace
    return ret = min(solve(word1, word2, idx1, idx2 + 1), min(solve(word1, word2, idx1 + 1, idx2), solve(word1, word2, idx1 + 1, idx2 + 1))) + 1;
}

int minDistance(string word1, string word2)
{
    n = word1.size(), m = word2.size();
    memset(dp, -1, sizeof(dp));
    return solve(word1, word2, 0, 0);

    // Bottom Up
    int n = word1.size(), m = word2.size();
    int dp[505][505];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 505;++i)
    {
        dp[i][m] = n - i;
        dp[n][i] = m - i;
    }

    for (int idx1 = n-1; idx1 >= 0;--idx1)
    {
        for (int idx2 = m - 1; idx2 >= 0;--idx2)
        {
            if(word1[idx1] == word2[idx2])
                dp[idx1][idx2] = dp[idx1 + 1][idx2 + 1];
            else
            {
                dp[idx1][idx2] = min(dp[idx1][idx2 + 1], min(dp[idx1 + 1][idx2], dp[idx1 + 1][idx2 + 1])) + 1;
            }
        }
    }
    return dp[0][0];
}