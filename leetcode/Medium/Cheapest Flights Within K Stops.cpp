#include <vector>
#include <queue>
#include <climits>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < flights.size();++i)
    {
        int from = flights[i][0];
        int to = flights[i][1];
        G[from].push_back({to, flights[i][2]});
    }

    // {{cost, stops}, node}
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    pq.push({{0, 0}, src});
    vector<int> cst(n, -1);
    vector<int> stops(n, -1);
    while(!pq.empty())
    {
        pair<pair<int, int>, int> p = pq.top();
        pq.pop();
        int node = p.second;
        int cost = p.first.first;
        int stps = p.first.second;
        if(node == dst)
            return cost;
        stops[node] = stps;
        cst[node] = cost;
        for (int i = 0; i < G[node].size();++i)
        {
            int to = G[node][i].first;
            if(to == dst || stps < k)
            {
                if(stps + 1 < stops[to] || cst[to] == -1)
                    pq.push({{cost + G[node][i].second, stps + (to != dst)}, to});
            }
        }
    }
    return -1;
}