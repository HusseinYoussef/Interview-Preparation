#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    int cst[n + 1];
    memset(cst, -1, sizeof(cst));
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 0; i < times.size();++i)
    {
        G[times[i][0]].push_back({times[i][1], times[i][2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int node = p.second;
        int cost = p.first;
        if(cst[node] != -1)
            continue;
        cst[node] = cost;
        for (int i = 0; i < G[node].size();++i)
        {
            int to = G[node][i].first;
            if(cst[to] == -1)
                pq.push({cost + G[node][i].second, to});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n;++i)
    {
        if(cst[i] == -1)
            return -1;
        ans = max(ans, cst[i]);
    }
    return ans;
}