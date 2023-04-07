#include <vector>
#include <cstring>

using namespace std;

int n, m;
int vis[505][505];
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { 1, -1, 0, 0};
int sz = 0;
bool valid(int x, int y, vector<vector<int>>& grid)
{
    return x < n && x >= 0 && y < m && y >= 0 && grid[x][y] == 1 && !vis[x][y];
}

void dfs(int x, int y, vector<vector<int>>& grid)
{
    vis[x][y] = 1;
    ++sz;

    for(int i = 0;i<4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny , grid))
            dfs(nx, ny, grid);
    }
}

int numEnclaves(vector<vector<int>>& grid)
{
    n = grid.size(), m = grid[0].size();
    memset(vis, 0, sizeof(vis));
    for(int i = 0;i<n;++i)
    {
        if (grid[i][0] == 1 && !vis[i][0])
            dfs(i, 0, grid);

        if (grid[i][m-1] == 1 && !vis[i][m-1])
            dfs(i, m-1, grid);
    }

    for(int i = 0;i<m;++i)
    {
        if (grid[0][i] == 1 && !vis[0][i])
            dfs(0, i, grid);

        if (grid[n-1][i] == 1 && !vis[n-1][i])
            dfs(n-1, i, grid);
    }

    int ans = 0;

    for(int i = 0;i<n;++i)
    {
        for(int j = 0;j<m;++j)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                sz = 0;
                dfs(i, j, grid);
                ans += sz;
            }
        }
    }

    return ans;
}
