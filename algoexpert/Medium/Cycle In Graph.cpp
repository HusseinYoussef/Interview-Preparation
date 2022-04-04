
/*
    Problem Statement

    You're given a list of edges representing an unweighted, directed
    graph with at least one node. Write a function that returns a boolean
    representing whether the given graph contains a cycle.
*/

#include <vector>
#include <cstring>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

bool ans;
int vis[105];
void dfs(vector<vector<int>> &edges, int node)
{
    ans |= vis[node] == GREY;
    if(ans || vis[node] == BLACK)
        return;

    vis[node] = GREY;
    for (int i = 0; i < edges[node].size();++i)
        dfs(edges, edges[node][i]);
    vis[node] = BLACK;
}

bool cycleInGraph(vector<vector<int>> edges)
{
    int n = edges.size();
    ans = 0;
    memset(vis, WHITE, sizeof(vis));
    for (int i = 0; i < n;++i)
    {
        if(vis[i] == WHITE && ans == 0)
            dfs(edges, i);
    }
    return ans;
}