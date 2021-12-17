#include <iostream>
#include <vector>

using namespace std;

bool vis[305][305];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int m, n;
bool ok(vector<vector<char>>& grid, int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !vis[x][y];
}
void dfs(vector<vector<char>>& grid, int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(ok(grid, nx, ny))
        {
            dfs(grid, nx, ny);
        }
    }
}

int numIslands(vector<vector<char>>& grid)
{
    m = grid.size(), n = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < m;++i)
    {
        for (int j = 0; j < n;++j)
        {
            if(grid[i][j] == '1' && !vis[i][j])
            {
                ++cnt;
                dfs(grid, i, j);
            }
        }
    }
    return cnt;
}