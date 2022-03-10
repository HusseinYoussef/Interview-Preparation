#include <vector>
#include <map>

using namespace std;

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void dfs(vector<vector<int>> &grid, vector<pair<int, int>> &vec, int x, int y, int offx, int offy)
{
    grid[x][y] = 3;

    vec.push_back({x - offx, y - offy});
    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
        {
            dfs(grid, vec, nx, ny, offx, offy);
        }
    }
}
int numberofDistinctIslands(vector<vector<int>> &grid)
{
    n = grid.size(), m = grid[0].size();
    map<vector<pair<int, int>>, bool> mp;

    int ans = 0;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(grid[i][j] == 1)
            {
                vec.clear();
                dfs(grid, vec, i, j, i, j);

                if (mp[vec] == 0)
                {
                    mp[vec] = 1;
                    ++ans;
                }
            }
        }
    }
    return ans;
}