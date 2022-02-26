#include <vector>
#include <queue>
#include <map>

using namespace std;

int shortestPathLength(vector<vector<int>>& graph)
{
    int n = graph.size();
    // node, msk
    queue<pair<int, int>>q;
    map<pair<int, int>, int> dist;
    for(int i = 0;i<n;++i)
    {
        q.push({i, 1<<i});
        dist[{i, 1<<i}] = 0;
    }

    while(!q.empty())
    {
        pair<int, int> state = q.front();
        q.pop();
        int node = state.first;
        int msk = state.second;
        for(int i = 0;i<graph[node].size();++i)
        {
            int nxt = graph[node][i];
            int nxtmsk = msk | (1<<nxt);
            if(dist.find({nxt, nxtmsk}) == dist.end())
            {
                if(nxtmsk == (1 << n) - 1)
                    return dist[state] + 1;
                q.push({nxt, nxtmsk});
                dist[{nxt, nxtmsk}] = dist[state] + 1;
            }
        }
    }
    return 0;
}
