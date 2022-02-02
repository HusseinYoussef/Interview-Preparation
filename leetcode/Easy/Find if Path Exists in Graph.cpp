#include <vector>

using namespace std;

void dfs(vector<bool> &vis, vector<vector<int>> &G, int node, int des)
{
    vis[node] = 1;
    for (int i = 0; i < G[node].size(); ++i)
    {
        if (vis[des])
            return;
        if (!vis[G[node][i]])
            dfs(vis, G, G[node][i], des);
    }
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
{
    vector<vector<int>> G(n);
    vector<bool> vis(n, 0);
    for (int i = 0; i < edges.size();++i)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(vis, G, source, destination);
    return vis[destination];
}