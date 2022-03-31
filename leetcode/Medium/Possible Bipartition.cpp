#include <vector>
#include <cstring>

using namespace std;

bool ans = 1;
int vis[2005];
void dfs(vector<vector<int>> &G, int node, bool group)
{
    if(ans == 0)
        return;
    vis[node] = group;

    for (int i = 0; i < G[node].size();++i)
    {
        if(vis[G[node][i]] == -1)
            dfs(G, G[node][i], !group);
        else
            ans &= vis[G[node][i]] == !group;
    }
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes)
{
    vector<vector<int>> G(n+1);
    // use undirected edges, since u->v has same result of v->u, u and v should go in two different groups in both cases
    for (int i = 0; i < dislikes.size();++i)
    {
        int u = dislikes[i][0];
        int v = dislikes[i][1];
        G[u].push_back(v);
        G[v].push_back(u);
    }

    memset(vis, -1, sizeof(vis));
    for (int i = 1; i <= n;++i)
    {
        if(vis[i] == -1)
            dfs(G, i, 0);

        if(ans == 0)
            return false;
    }
    return true;
}