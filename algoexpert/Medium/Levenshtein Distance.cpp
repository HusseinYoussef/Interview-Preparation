
/*
    Problem Statement

    Write a function that takes in two strings and returns the minimum number of
    edit operations that need to be performed on the first string to obtain the
    second string.

    There are three edit operations: insertion of a character, deletion of a
    character, and substitution of a character for another.
*/
#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int dp[505][505];
int solve(string &str1, string &str2, int idx1, int idx2)
{
    if(idx1 == n && idx2 == m)
        return 0;

    // if str1 finishes first, then we must add the remaining chars to str1.
    // Similarly, if str2 finishes first, then we must delete the remaining chars from str1
    // so number of operations left that must be done = number of remaining chars (to be added or deleted in word1)    
    if(idx1 == n || idx2 == m)
        return n - idx1 + m - idx2;

    int &ret = dp[idx1][idx2];
    if(~ret)
        return ret;

    if(str1[idx1] == str2[idx2])
        return ret = solve(str1, str2, idx1 + 1, idx2 + 1);
    
    // Add, Delete, Replace
    return ret = min(solve(str1, str2, idx1, idx2 + 1), min(solve(str1, str2, idx1 + 1, idx2), solve(str1, str2, idx1 + 1, idx2 + 1))) + 1;
}

int levenshteinDistance(string str1, string str2)
{
    n = str1.size(), m = str2.size();
    memset(dp, -1, sizeof(dp));
    return solve(str1, str2, 0, 0);

    // Bottom Up
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
            if(str1[idx1] == str2[idx2])
                dp[idx1][idx2] = dp[idx1 + 1][idx2 + 1];
            else
            {
                dp[idx1][idx2] = min(dp[idx1][idx2 + 1], min(dp[idx1 + 1][idx2], dp[idx1 + 1][idx2 + 1])) + 1;
            }
        }
    }
    return dp[0][0];
}
