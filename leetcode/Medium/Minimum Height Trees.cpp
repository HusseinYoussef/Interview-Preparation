#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
{
    // Topological sort (O (V+E))
    vector<int> ans;
    if(n < 2)
    {
        for (int i = 0; i < n;++i)
            ans.push_back(i);
    }
    vector<vector<int>> G(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < edges.size();++i)
    {
        int v = edges[i][0], u = edges[i][1];
        G[v].push_back(u);
        G[u].push_back(v);
        indegree[v]++, indegree[u]++;
    }
    queue<int> q;
    for (int i = 0; i < n;++i)
    {
        if(indegree[i] == 1)
            q.push(i);
    }
    int remainingNodes = n;
    while(remainingNodes > 2)
    {
        int leafs = q.size();
        remainingNodes -= q.size();
        for (int i = 0; i < leafs;++i)
        {
            int leaf = q.front();
            q.pop();
            indegree[leaf]--;
            for (int j = 0; j < G[leaf].size(); ++j)
            {
                indegree[G[leaf][j]]--;
                if (indegree[G[leaf][j]] == 1)
                    q.push(G[leaf][j]);
            }
        }
    }
    while(!q.empty())
        ans.push_back(q.front()), q.pop();
    return ans;
}

int main()
{
    vector<vector<int>> vec = {};
    findMinHeightTrees(6, vec);
    return 0;
}