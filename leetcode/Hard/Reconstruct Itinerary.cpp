#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
vector<string> ans;
void dfs(unordered_map<string, vector<string>> &G, string node, vector<string> &path)
{
    if(path.size() == n+1)
    {
        ans = path;
        return;
    }

    for(int i =0; i< G[node].size() && ans.empty(); i++)
    {
        string to = G[node][i];
        // remove edge in order not to use it again later in the same path
        G[node].erase(G[node].begin() + i);
        path.push_back(to);
        dfs(G, to, path);
        // revert changes
        G[node].insert(G[node].begin() + i, to);
        path.pop_back();
    }
}

vector<string> findItinerary(vector<vector<string>>& tickets)
{
    n = tickets.size();
    unordered_map<string, vector<string>> G;
    for (int i = 0; i < n;++i)
        G[tickets[i][0]].push_back(tickets[i][1]);

    for(auto &p : G)
        sort(p.second.begin(), p.second.end());

    vector<string> pth = {"JFK"};
    dfs(G, "JFK", pth);
    return ans;
}