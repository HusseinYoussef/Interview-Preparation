#include <vector>
#include <cstring>

using namespace std;

int n, m;
int dp[205][205];
int solve(vector<vector<int>>& grid, int r, int c)
{
    if(r == n || c == m)
        return 1e8;
    if(r == n-1 && c == m-1)
        return grid[r][c];

    int &ret = dp[r][c];
    if(~ret)
        return ret;

    return ret = min(solve(grid, r + 1, c), solve(grid, r, c + 1)) + grid[r][c];
}

int minPathSum(vector<vector<int>>& grid)
{
    memset(dp, -1, sizeof(dp));
    n = grid.size(), m = grid[0].size();
    return solve(grid, 0, 0);

    // Bottom-Up
    int n = grid.size(), m = grid[0].size();
    int dp[205][205];
    dp[n - 1][m - 1] = grid[n - 1][m - 1];
    for (int i = n - 2; i >= 0;--i)
        dp[i][m - 1] = dp[i + 1][m - 1] + grid[i][m - 1];
    for (int i = m - 2; i >= 0;--i)
        dp[n - 1][i] = dp[n - 1][i + 1] + grid[n - 1][i];

    for (int r = n - 2; r >= 0;--r)
    {
        for (int c = m - 2; c >= 0;--c)
        {
            dp[r][c] = min(dp[r + 1][c], dp[r][c + 1]) + grid[r][c];
        }
    }
    return dp[0][0];
}