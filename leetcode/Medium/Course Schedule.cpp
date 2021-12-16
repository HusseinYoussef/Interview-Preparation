#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
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
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        --numCourses;
        for (int i = 0; i < G[node].size();++i)
        {
            indegree[G[node][i]]--;
            if(indegree[G[node][i]] == 0)
                q.push(G[node][i]);
        }
    }
    return numCourses == 0;
}