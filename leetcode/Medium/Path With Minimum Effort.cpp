#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumEffortPath(vector<vector<int>>& heights)
{
    int n = heights.size(), m = heights[0].size();

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<vector<int>> dist(n, vector<int>(m, -1));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cst = pq.top().first;
        pq.pop();
        
        if(x == n-1 && y == m-1)
            return cst;
        if(dist[x][y] == -1)
            dist[x][y] = cst;
        else
            continue;

        for (int i = 0; i < 4;++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1)
            {
                int diff = abs(heights[x][y] - heights[nx][ny]);
                pq.push({max(cst, diff), {nx, ny}});
            }
        }
    }
    return 0;
}