#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> G(numCourses);
    vector<int> indegree(numCourses);
    for (int i = 0; i < prerequisites.size();++i)
    {
        int v = prerequisites[i][0], u = prerequisites[i][1];
        indegree[v]++;
        G[u].push_back(v);
    }
    queue<int> q;
    for (int i = 0; i < numCourses;++i)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int i = 0; i < G[node].size();++i)
        {
            indegree[G[node][i]]--;
            if(indegree[G[node][i]] == 0)
                q.push(G[node][i]);
        }
    }
    if(ans.size() == numCourses)
        return ans;
    return {};
}