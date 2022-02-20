#include <iostream>
#include <cstring>

using namespace std;

int expand(string &s, int l, int r)
{
    int i = l, j = r;
    int cnt = 0;
    while(i >= 0 && j < s.size() && s[i] == s[j])
    {
        if(i == j)
            cnt++;
        else
            cnt += 2;
        --i, ++j;
    }
    return cnt;
}

string longestPalindrome(string s)
{
    // Try every center
    // O(n^2)
    int n = s.size();
    int len = 0;
    int idx;
    for (int i = 0; i < n;++i)
    {
        int l1 = expand(s, i, i);
        int l2 = (i + 1 < n) ? expand(s, i, i + 1) : 0;
        
        if(l1 > len)
        {
            len = l1;
            idx = i - (len / 2);
        }
        if(l2 > len)
        {
            len = l2;
            idx = i - ((len / 2) - 1);
        }
    }
    return s.substr(idx, len);
}

// DP - Bottom Up Solution
string longestPalindrome2(string s)
{
    int n = s.size();
    int mx = 0;
    int idx = 0;
    bool dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0;--i)
    {
        for (int j = i; j < n;++j)
        {
            dp[i][j] = (s[i] == s[j]) && (j - i <= 1 || dp[i + 1][j - 1]);
            if(dp[i][j] && j-i+1 > mx)
            {
                mx = j-i+1;
                idx = i;
            }
        }
    }
    return s.substr(idx, mx);
}