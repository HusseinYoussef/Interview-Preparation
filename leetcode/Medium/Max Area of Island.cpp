#include <iostream>
#include <vector>

using namespace std;

int n, m;
int ans = 0, cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(vector<vector<int>>& grid, int x, int y)
{
    ++cnt;
    grid[x][y] |= (1 << 1);
    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
        {
            dfs(grid, nx, ny);
        }
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(grid[i][j] == 1)
            {
                cnt = 0;
                dfs(grid, i, j);
                ans = max(ans, cnt);
            }
        }
    }
    return ans;
}