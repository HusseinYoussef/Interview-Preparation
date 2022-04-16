#include <iostream>
#include <cstring>

using namespace std;

int dp[22][32];
int solve(string &s, string &p, int sidx, int pidx)
{
    if(sidx == s.size() && pidx == p.size())
        return 1;
    
    if(pidx == p.size())
        return 0;

    int &ret = dp[sidx][pidx];
    if(~ret)
        return ret;

    ret = 0;
    // match 0 or more char
    if(pidx + 1 < p.size() && p[pidx+1] == '*')
    {
        // match 0 char
        ret = solve(s, p, sidx, pidx + 2);
        // match more
        if(sidx < s.size() && (s[sidx] == p[pidx] || p[pidx] == '.'))
            return ret |= solve(s, p, sidx + 1, pidx);
    }
    else
    {
        if(sidx < s.size() && (s[sidx] == p[pidx] || p[pidx] == '.'))
            return ret = solve(s, p, sidx + 1, pidx + 1);
    }
    return ret;
}

bool isMatch(string s, string p)
{
    memset(dp, -1, sizeof(dp));
    return solve(s, p, 0, 0);

    
    // **** Bottom-Up ****

    int dp[22][32];
    memset(dp, 0, sizeof(dp));

    // Base Case
    dp[s.size()][p.size()] = 1;

    for (int sidx = s.size(); sidx >= 0;--sidx)
    {
        for (int pidx = p.size() - 1; pidx >= 0;--pidx)
        {
            if(pidx + 1 < p.size() && p[pidx+1] == '*')
            {
                // match 0 char
                dp[sidx][pidx] = dp[sidx][pidx + 2];
                // match more
                if(sidx < s.size() && (s[sidx] == p[pidx] || p[pidx] == '.'))
                    dp[sidx][pidx] |= dp[sidx + 1][pidx];
            }
            else
            {
                if(sidx < s.size() && (s[sidx] == p[pidx] || p[pidx] == '.'))
                    dp[sidx][pidx] = dp[sidx + 1][pidx + 1];
            }
        }
    }
    return dp[0][0];
}