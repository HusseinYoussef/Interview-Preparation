#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    int n = strs.size(), idx = 1;
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    for (int i = 0; i < n;++i)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        if(!mp[s])
        {
            mp[s] = idx;
            ans.push_back({strs[i]});
            ++idx;
        }
        else
        {
            ans[mp[s] - 1].push_back(strs[i]);
        }
    }
    return ans;
}