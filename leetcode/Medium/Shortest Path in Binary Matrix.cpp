#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    int n = grid.size();
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;
    if(n == 1)
        return 1;
    queue<pair<int, int>> q;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    q.push({0, 0});
    grid[0][0] = 1;
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        int cst = grid[x][y];
        for (int i = 0; i < 8;++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx == n-1 && ny == n-1)
                return cst + 1;
            if(nx >= 0 && nx < n && ny >=0 && ny < n && grid[nx][ny] == 0)
            {
                q.push({nx, ny});
                grid[nx][ny] = cst + 1;
            }
        }
    }
    return -1;
}