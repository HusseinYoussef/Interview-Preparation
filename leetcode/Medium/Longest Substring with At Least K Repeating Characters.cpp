#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int countUnique(string &s)
{
    vector<bool> c(26, 0);
    int cnt = 0;
    for (int i = 0; i < s.size();++i)
    {
        cnt += c[s[i] - 'a'] == 0;
        c[s[i] - 'a'] = 1;
    }
    return cnt;
}

int longestSubstring(string s, int k)
{
    int n = s.size();
    int MaxUnique = countUnique(s);
    int freq[26], ans = 0;
    for (int currUnique = 1; currUnique <= MaxUnique; ++currUnique)
    {
        memset(freq, 0, sizeof(freq));
        int l = 0, r = 0, unique = 0, cntAtLeastK = 0;
        while(r < n)
        {
            if(freq[s[r]-'a'] || unique < currUnique)
            {
                int idx = s[r] - 'a';
                ++freq[idx];
                if(freq[idx] == 1)
                    ++unique;
                if(freq[idx] == k)
                    ++cntAtLeastK;
                ++r;
            }
            else
            {
                int idx = s[l] - 'a';
                --freq[idx];
                if(freq[idx] == 0)
                    --unique;
                if(freq[idx] == k-1)
                    --cntAtLeastK;
                ++l;
            }
            if(unique == cntAtLeastK)
                ans = max(ans, r - l);
        }
    }
    return ans;
}