#include <vector>

using namespace std;

int sz;
bool vis[100005];
void dfs(int node, vector<vector<int>> &G)
{
    ++sz;
    vis[node] = 1;

    for(int i = 0;i<G[node].size();++i)
    {
        if(!vis[G[node][i]])
            dfs(G[node][i], G);
    }
}

long long sumOfProductOfAllPairs(vector<int> &vec)
{
    // (a + b + c)^2 = a^2 + b^2 + c^2 + 2*(a*b + b*c + c*a)
    long long sum = 0, squaresSum = 0;
    for(int i = 0;i<vec.size();++i)
    {
        sum += vec[i];
        squaresSum += (long long)vec[i] * vec[i];
    }
    return ((sum * sum) - squaresSum) / 2;
}

long long countPairs(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> G(n);
    memset(vis, 0, sizeof(vis));

    for(int i = 0;i<edges.size();++i)
    {
        G[edges[i][0]].push_back(edges[i][1]);
        G[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> componentsSizes;
    for(int i = 0;i<n;++i)
    {
        if (!vis[i])
        {
            sz = 0;
            dfs(i, G);
            componentsSizes.push_back(sz);
        }
    }
    return sumOfProductOfAllPairs(componentsSizes);
}
