#include <vector>
#include <queue>
#include <climits>

using namespace std;

void wallsAndGates(vector<vector<int>> &rooms)
{
    int n = rooms.size(), m = rooms[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(rooms[i][j] == 0)
                q.push({i, j});
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4;++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && rooms[nx][ny] == INT_MAX)
            {
                rooms[nx][ny] = rooms[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}