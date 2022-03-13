#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int par[1005];
int find(int v)
{
    if(v == par[v])
        return v;
    return par[v] = find(par[v]);
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
    int n = accounts.size();
    for (int i = 0; i < n;++i)
        par[i] = i;
    unordered_map<string, int> mp;
    for (int i = 0; i < n;++i)
    {
        for (int j = 1; j < accounts[i].size();++j)
        {
            if(mp.find(accounts[i][j]) != mp.end())
            {
                int u = find(i);
                int v = find(mp[accounts[i][j]]);
                par[u] = v;
            }
            else
                mp[accounts[i][j]] = i;
        }
    }
    unordered_map<int, set<string>> st;

    for (int i = 0; i < n;++i)
    {
        for (int j = 1; j < accounts[i].size();++j)
        {
            int u = find(i);
            st[u].insert(accounts[i][j]);
        }
    }
    vector<vector<string>> ans;
    for(auto &p : st)
    {
        vector<string> tmp = {accounts[p.first][0]};
        for(string s : p.second)
        {
            tmp.push_back(s);
        }
        ans.push_back(tmp);
    }
    return ans;
}