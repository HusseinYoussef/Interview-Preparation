#include <iostream>
#include <cstring>

using namespace std;

int dp[502][502];
int solve(string &word1, string &word2, int idx1, int idx2)
{
    if(idx1 == word1.size() || idx2 == word2.size())
        return word1.size() - idx1 + word2.size() - idx2;

    int &ret = dp[idx1][idx2];
    if(~ret)
        return ret;
    
    if(word1[idx1] == word2[idx2])
        return ret = solve(word1, word2, idx1 + 1, idx2 + 1);

    return ret = min(solve(word1, word2, idx1 + 1, idx2), solve(word1, word2, idx1, idx2 + 1)) + 1;
}

int minDistance(string word1, string word2)
{
    memset(dp, -1, sizeof(dp));
    return solve(word1, word2, 0, 0);

    // Bottom Up
    int dp[502][502];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 502;++i)
    {
        dp[i][word2.size()] = word1.size() - i;
        dp[word1.size()][i] = word2.size() - i;
    }

    for (int idx1 = word1.size() - 1; idx1 >= 0;--idx1)
    {
        for (int idx2 = word2.size() - 1; idx2 >= 0;--idx2)
        {
            if(word1[idx1] == word2[idx2])
                dp[idx1][idx2] = dp[idx1 + 1][idx2 + 1];
            else
                dp[idx1][idx2] = min(dp[idx1 + 1][idx2], dp[idx1][idx2 + 1]) + 1;
        }
    }
    return dp[0][0];
}