#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();
    int num = 0;
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(grid[i][j] == 1)
                ++num;
            else if(grid[i][j] == 2)
                q.push({0, {i, j}});
        }
    }
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int ans = 0;
    while(!q.empty())
    {
        pair<int, pair<int, int>> p = q.front();
        q.pop();
        int mins = p.first;
        ans = max(ans, mins);
        int x = p.second.first, y = p.second.second;
        for (int i = 0; i < 4;++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == 1)
            {
                q.push({mins + 1, {nx, ny}});
                --num;
                grid[nx][ny] = 2;
            }
        }
    }
    if(num == 0)
        return ans;
    return -1;
}