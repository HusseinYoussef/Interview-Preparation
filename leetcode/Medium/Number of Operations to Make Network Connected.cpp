#include <vector>

using namespace std;

int par[100005];
int find(int v)
{
    if(par[v] == v)
        return v;
    return par[v] = find(par[v]);
}

int makeConnected(int n, vector<vector<int>>& connections)
{
    for(int i = 0;i<=n;++i)
        par[i] = i;

    int spareConnections = 0;
    for(int i = 0;i<connections.size();++i)
    {
        int u = find(connections[i][0]);
        int v = find(connections[i][1]);

        if (u != v)
            par[u] = v;
        else
            ++spareConnections;
    }
    int cc = 0;
    for(int i = 0;i<n;++i)
        cc += find(i) == i;


    if (spareConnections >= cc - 1)
        return cc - 1;
    return -1;
}
