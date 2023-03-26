#include <vector>
#include <cstring>

using namespace std;

// Graph coloring
const int WHITE = 0;
const int BLACK = -1;
// Gray any number else

int vis[100005];
int ans = -1;
void dfs(int node, vector<int>& edges, int num)
{
    vis[node] = num;
    if (edges[node] != -1)
    {
        if (vis[edges[node]] == WHITE)
            dfs(edges[node], edges, num + 1);
        else if(vis[edges[node]] != BLACK) // Gray
            ans = max(ans, num - vis[edges[node]] + 1);
    }
    vis[node] = BLACK;
}

int longestCycle(vector<int>& edges)
{
    int n = edges.size();
    vector<vector<int>> G(n);
    ans = -1;
    memset(vis, WHITE, sizeof(vis));

    for(int i = 0;i<n;++i)
    {
        if(vis[i] == WHITE)
            dfs(i, edges, 1);
    }

    return ans;
}
