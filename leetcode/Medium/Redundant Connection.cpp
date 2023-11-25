#include <vector>

using namespace std;

int par[1005];
int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges)
{
    int n = edges.size();
    for (int i = 0;i<=n+1;++i)
        par[i] = i;

    for (int i = 0;i<n;++i)
    {
        int u = find(edges[i][0]);
        int v = find(edges[i][1]);

        if (u != v)
            par[u] = v;
        else
            return edges[i];
    }
    return {};
}
