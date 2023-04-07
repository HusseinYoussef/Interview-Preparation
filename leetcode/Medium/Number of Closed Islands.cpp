#include <vector>
#include <cstring>

using namespace std;

int n, m;
int vis[105][105];
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { 1, -1, 0, 0};

bool valid(int x, int y, vector<vector<int>>& grid)
{
    return x < n && x >= 0 && y < m && y >= 0 && grid[x][y] == 0 && !vis[x][y];
}

void dfs(int x, int y, vector<vector<int>>& grid)
{
    vis[x][y] = 1;

    for(int i = 0;i<4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny , grid))
            dfs(nx, ny, grid);
    }
}

int closedIsland(vector<vector<int>>& grid)
{
    n = grid.size(), m = grid[0].size();

    for(int i = 0;i<n;++i)
    {
        if (grid[i][0] == 0 && !vis[i][0])
            dfs(i, 0, grid);

        if (grid[i][m-1] == 0 && !vis[i][m-1])
            dfs(i, m-1, grid);
    }

    for(int i = 0;i<m;++i)
    {
        if (grid[0][i] == 0 && !vis[0][i])
            dfs(0, i, grid);

        if (grid[n-1][i] == 0 && !vis[n-1][i])
            dfs(n-1, i, grid);
    }

    int ans = 0;

    for(int i = 0;i<n;++i)
    {
        for(int j = 0;j<m;++j)
        {
            if (grid[i][j] == 0 && !vis[i][j])
            {
                dfs(i, j, grid);
                ++ans;
            }
        }
    }

    return ans;
}
