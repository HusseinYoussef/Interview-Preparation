#include <iostream>
#include <cstring>

using namespace std;


bool isPalindrome(string &s, int l, int r)
{
    while(l < r)
    {
        if(s[l++] != s[r--])
            return false;
    }
    return true;
}

int dp[2002];
int solve(string &s, int idx)
{
    if(idx == s.size())
        return 0;
    
    int &ret = dp[idx];
    if(~ret)
        return ret;
    
    ret = 1e8;
    for(int i = idx;i<s.size();++i)
    {
        if(isPalindrome(s, idx, i))
        {
            ret = min(ret, solve(s, i+1)+1);
        }
    }
    return ret;
}

int minCut(string s)
{
    memset(dp, -1, sizeof(dp));
    return solve(s, 0) - 1;

    // **** Bottom Up ****
    int dp[2002];
    dp[s.size()] = 0;
    for(int idx = s.size()-1;idx>=0;--idx)
    {
        dp[idx] = 1e8;
        for(int i = idx;i<s.size();++i)
        {
            if(isPalindrome(s, idx, i))
                dp[idx] = min(dp[idx], dp[i+1]+1);
        }
    }
    return dp[0]-1;
}