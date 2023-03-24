#include <vector>

using namespace std;

int ans;
bool vis[50005];
void dfs(int node, vector<vector<pair<int, bool>>> &G)
{
    vis[node] = 1;
    for(int i = 0;i<G[node].size();++i)
    {
        if(!vis[G[node][i].first])
        {
            ans += G[node][i].second;
            dfs(G[node][i].first, G);
        }
    }
}

int minReorder(int n, vector<vector<int>>& connections)
{
    ans = 0;
    memset(vis, 0, sizeof(vis));
    // root at node 0
    // use undirected edges and a bool to indicate whether it from parent->child (1) or child -> parent (0)
    vector<vector<pair<int, bool>>> G(50005);

    for(int i = 0;i<connections.size();++i)
    {
        G[connections[i][0]].push_back({connections[i][1], 1}); // this is the original given edge
        G[connections[i][1]].push_back({connections[i][0], 0}); // (artificial) reversed to get to all nodes that reach 0
    }

    dfs(0, G);
    return ans;
}
