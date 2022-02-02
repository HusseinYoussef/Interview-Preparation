#include <vector>

using namespace std;

const int N = 10004;
int par[N];
int find(int v)
{
    if(v == par[v])
        return v;
    return par[v] = find(par[v]);
}

bool validTree(int n, vector<vector<int>> &edges)
{
    if(edges.size() != n-1)
        return false;

    for (int i = 0; i < N;++i)
        par[i] = i;
    for (int i = 0; i < edges.size();++i)
    {
        int a = find(edges[i][0]);
        int b = find(edges[i][1]);
        if(a != b)
            par[b] = a;
    }
    // must be 1 connected component
    for (int i = 0; i < n;++i)
    {
        if(find(i) != find(0))
            return false;
    }
    return true;
}