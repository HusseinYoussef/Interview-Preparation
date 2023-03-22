#include <vector>

using namespace std;

int par[100005];
int find(int u)
{
    if(u == par[u])
        return u;
    return par[u] = find(par[u]);
}

int minScore(int n, vector<vector<int>>& roads)
{
    for(int i = 0;i<=n;++i)
        par[i] = i;

    for(int i = 0;i<roads.size();++i)
    {
        int u = find(roads[i][0]);
        int v = find(roads[i][1]);
        if(u != v)
            par[v] = u;
    }
    int ans = INT_MAX;
    int st = find(1);
    for(int i = 0;i<roads.size();++i)
    {
        int u = find(roads[i][0]);

        if (u == st)
            ans = min(ans, roads[i][2]);
    }

    return ans;
}
