#include <vector>
#include <cstring>

using namespace std;

int ans = 1;
int vis[105];
void dfs(vector<vector<int>>& graph, int node, bool set)
{
    if(ans == 0)
        return;
    vis[node] = set;
    for (int i = 0; i < graph[node].size();++i)
    {
        if(vis[graph[node][i]] == -1)
            dfs(graph, graph[node][i], !set);
        else
            ans &= vis[graph[node][i]] == !set;     // make sure the neighbouring node is on the other set (not current set)
    }
}

bool isBipartite(vector<vector<int>>& graph)
{
    int n = graph.size();
    memset(vis, -1, sizeof(vis));

    // for every connected component, check if it is Bipartite
    for (int i = 0; i < n;++i)
    {
        if(vis[i] == -1)
            dfs(graph, i, 0);
        if(ans == 0)
            return false;
    }
    return ans;
}