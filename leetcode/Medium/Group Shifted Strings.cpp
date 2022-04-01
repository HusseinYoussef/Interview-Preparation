#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupStrings(vector<string> &strings)
{
    int n = strings.size();
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    int idx = 0;
    for (int i = 0; i < n;++i)
    {
        string diffs = "";
        for (int j = 1; j < strings[i].size();++j)
        {
            diffs  += (strings[i][j]  - strings[i][j-1] + 26) % 26 + 'a';
        }
        if(mp.find(diffs) != mp.end())
            ans[mp[diffs]].push_back(strings[i]);
        else
        {
            ans.push_back({strings[i]});
            mp[diffs] = idx++;
        }
    }
    return ans;
}