#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2)
{
    int dp[102][102];
    memset(dp, 0, sizeof(dp));

    for (int idx1 = str1.size() - 1; idx1 >= 0;--idx1)
    {
        for (int idx2 = str2.size() - 1; idx2 >= 0;--idx2)
        {
            if(str1[idx1] == str2[idx2])
                dp[idx1][idx2] = dp[idx1 + 1][idx2 + 1] + 1;
            else
                dp[idx1][idx2] = max(dp[idx1 + 1][idx2], dp[idx1][idx2 + 1]);
        }
    }
    int mxlen = dp[0][0];

    vector<char> ans;
    for (int idx1 = 0; idx1 < str1.size();++idx1)
    {
        for (int idx2 = 0; idx2 < str2.size();++idx2)
        {
            if(str1[idx1] == str2[idx2] && mxlen && dp[idx1][idx2] == mxlen)
            {
                ans.push_back(str1[idx1]);
                --mxlen;
                break;
            }
        }
    }
    return ans;
}