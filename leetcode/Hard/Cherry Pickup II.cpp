#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int dx[3] = {1, 1, 1};
int dy[3] = {-1, 0, 1};
int dp[72][72][72];
int solve(vector<vector<int>>& grid, int r, int c1, int c2)
{
    int &ret = dp[r][c1][c2];
    if(~ret)
        return ret;
    ret = 0;
    
    if(r == n-1)
        return ret = ((c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2]);

    for (int i = 0; i < 3;++i)
    {
        int nr = r + dx[i], nc1 = c1 + dy[i];
        if(nr >= 0 && nr < n && nc1 >= 0 && nc1 < m)
        {
            for (int j = 0; j < 3;++j)
            {
                int nc2 = c2 + dy[j];
                if (nc2 >= 0 && nc2 < m)
                {
                    ret = max(ret, solve(grid, nr, nc1, nc2) + ((c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2]));
                }
            }
        }
    }
    return ret;
}

int cherryPickup(vector<vector<int>>& grid)
{
    n = grid.size(), m = grid[0].size();
    memset(dp, -1, sizeof(dp));
    return solve(grid, 0, 0, m - 1);
}