#include <vector>

using namespace std;

int time = 0;
// Tarjan's Algorithm
void dfs(vector<vector<int>> &ans, vector<vector<int>> &G,vector<int> &disc, vector<int> &low, int node, int parent=-1)
{
    disc[node] = low[node] = time++;
    for (int i = 0; i < G[node].size();++i)
    {
        int to = G[node][i];
        if(to == parent)
            continue;
        if(disc[to] == -1)
            dfs(ans, G, disc, low, to, node);

        low[node] = min(low[node], low[to]);

        // Bridge
        if(low[to] > disc[node])
            ans.push_back({node, to});
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
{
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < connections.size();++i)
    {
        int u = connections[i][0], v = connections[i][1];
        G[v].push_back(u);
        G[u].push_back(v);
    }

    vector<vector<int>> ans;
    vector<int> disc(n + 1, -1);
    vector<int> low(n + 1, -1);

    for (int i = 0; i < n;++i)
    {
        if(disc[i] == -1)
            dfs(ans, G, disc, low, i);
    }
    return ans;
}