#include <iostream>
#include <vector>

using namespace std;

int n, m;
int ans = 0;
int endx, endy;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
// O(3 ^ N)
// use the 3rd bit as vis
void dfs(vector<vector<int>>& grid, int x, int y, int empty)
{
    if(x == endx && y == endy)
    {
        if(empty == 0)
            ++ans;
        return;
    }
    // vis
    grid[x][y] |= (1 << 2);
    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && (grid[nx][ny] & ((1 << 2) - 1)) != 3 && (grid[nx][ny] & (1 << 2)) == 0)
        {
            dfs(grid, nx, ny, empty - (grid[nx][ny] == 0));
        }
    }
    // set 3rd vis bit to 0
    grid[x][y] &= ((1 << 2) - 1);
}

int uniquePathsIII(vector<vector<int>>& grid)
{
    // 0 empty, -1 block
    n = grid.size(), m = grid[0].size();
    int empty = 0, startx, starty;
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(grid[i][j] == 1)
                startx = i, starty = j;
            else if(grid[i][j] == 2)
                endx = i, endy = j;
            else if(grid[i][j] == -1)
                grid[i][j] = 3;
            else
                ++empty;
        }
    }
    dfs(grid, startx, starty, empty);
    return ans;
}