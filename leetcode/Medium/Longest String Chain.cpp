#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1005];
unordered_map<string, int> mp;
int solve(vector<string>& words, int idx)
{
    int &ret = dp[idx];
    if(~ret)
        return ret;
    
    ret = 0;
    for(int i = 0;i<words[idx].size();++i)
    {
        string tmp = words[idx];
        tmp.erase(i, 1);
        
        if(mp.find(tmp) != mp.end())
            ret = max(ret, solve(words, mp[tmp]) + 1);
    }
    return ret;
}

bool static cmp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int longestStrChain(vector<string>& words)
{
    int n = words.size();
    sort(words.begin(), words.end(), cmp);
    unordered_map<string, int> mp;
    for(int i = 0;i<n;++i)
    {
        mp[words[i]] = i;
    }

    memset(dp, -1, sizeof(dp));
    int ans = 1;
    for(int i = 0;i<n;++i)
    {
        ans = max(ans, solve(words, i) + 1);
    }

    int dp[1005];
    int ans = 0;
    for(int idx = 0;idx<n;++idx)
    {
        dp[idx] = 1;
        for(int i = 0;i<words[idx].size();++i)
        {
            string tmp = words[idx];
            tmp.erase(i, 1);
            if(mp.find(tmp) != mp.end())
                dp[idx] = max(dp[idx], dp[mp[tmp]] + 1);
        }
        ans = max(ans, dp[idx]);
    }
    return ans;
}