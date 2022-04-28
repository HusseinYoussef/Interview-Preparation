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

/*  loop Detection using Graph Coloring
    int white = 0;
    int grey = 1;
    int black = 2;
    int vis[100005];
    bool loop = 0;
    void dfs(vector<vector<int>> &G, int node)
    {
        vis[node] = grey;
        for(int i = 0;i<G[node].size();++i)
        {
            if(vis[G[node][i]] == grey)
                loop = 1;
            else if(vis[G[node][i]] == white)
                dfs(G, G[node][i]);
        }
        vis[node] = black;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> G(numCourses+1);
        
        for(int i = 0;i<prerequisites.size();++i)
        {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            G[u].push_back(v);
        }
		memset(vis, 0, sizeof(vis));
        for(int i = 0;i<numCourses;++i)
        {
            if(vis[i] == 0 && loop == 0)
                dfs(G, i);
        }
        return !loop;
    }
*/