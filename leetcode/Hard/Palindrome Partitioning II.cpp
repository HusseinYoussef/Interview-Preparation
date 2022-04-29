#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[2002];
int solve(string &s, vector<vector<bool>> &palindrome_dp, int idx)
{
    if(idx == s.size())
        return 0;
    
    int &ret = dp[idx];
    if(~ret)
        return ret;
    
    ret = 1e8;
    for(int i = idx;i<s.size();++i)
    {
        if(palindrome_dp[idx][i])
        {
            ret = min(ret, solve(s, palindrome_dp, i + 1) + 1);
        }
    }
    return ret;
}

int minCut(string s)
{
    // O(n^2)
    // DP as precomputation ~ palindrome_dp[l][r] = whether substring from (l to r) is palindrome or not
    vector<vector<bool>> palindrome_dp(2002, vector<bool>(2002));
    for (int l = s.size() - 1; l >= 0;--l)
    {
        for (int r = l; r < s.size();++r)
        {
            if(r - l <= 1)
                palindrome_dp[l][r] = s[l] == s[r];
            else
                palindrome_dp[l][r] = (s[l] == s[r]) && palindrome_dp[l + 1][r - 1];
        }
    }

    memset(dp, -1, sizeof(dp));
    return solve(s, palindrome_dp, 0) - 1;

    // **** Bottom Up ****
    int dp[2002];
    dp[s.size()] = 0;
    for(int idx = s.size()-1;idx>=0;--idx)
    {
        dp[idx] = 1e8;
        for(int i = idx;i<s.size();++i)
        {
            if(palindrome_dp[idx][i])
                dp[idx] = min(dp[idx], dp[i+1]+1);
        }
    }
    return dp[0] - 1;
}