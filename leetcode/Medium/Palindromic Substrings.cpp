#include <iostream>
#include <cstring>

using namespace std;

int countSubstrings(string s)
{
    int n = s.size();
    int ans = 0;
    bool dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    // is substr from i->j palindrome or not
    for (int i = n - 1; i >= 0;--i)
    {
        for (int j = i; j < n;++j)
        {
            dp[i][j] = (s[i] == s[j]) && (j - i <= 1 || dp[i + 1][j - 1]);
            ans += dp[i][j];
        }
    }
    return ans;
}