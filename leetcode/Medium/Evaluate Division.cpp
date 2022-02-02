#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool f = 0;
double res = 0;
void dfs(unordered_map<string, bool> &vis, unordered_map<string, vector<pair<string, double>>> &G, string &node, string &des, double val)
{
    if(node == des)
    {
        f = 1;
        res = val;
        return;
    }
    vis[node] = 1;
    for (int i = 0; i < G[node].size();++i)
    {
        if(vis[G[node][i].first] == 0)
        {
            dfs(vis, G, G[node][i].first, des, val * G[node][i].second);
        }
    }
    vis[node] = 0;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
    unordered_map<string, vector<pair<string, double>>> G;
    for (int i = 0; i < equations.size();++i)
    {
        string u = equations[i][0];
        string v = equations[i][1];
        G[u].push_back({v, values[i]});
        G[v].push_back({u, 1 / values[i]});
    }
    unordered_map<string, bool> vis;
    vector<double> ans;
    for (int i = 0; i < queries.size();++i)
    {
        string u = queries[i][0];
        string v = queries[i][1];
        if(G.find(u) == G.end())
        {
            ans.push_back(-1);
            continue;
        }
        f = 0;
        dfs(vis, G, u, v, 1);
        if(f)
            ans.push_back(res);
        else
            ans.push_back(-1);
    }
    return ans;
}