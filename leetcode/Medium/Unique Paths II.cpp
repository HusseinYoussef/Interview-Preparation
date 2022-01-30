#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int n, m;
int dp[105][105];
int solve(vector<vector<int>>& obstacleGrid, int i, int j)
{
    if(i == n || j == m || obstacleGrid[i][j] == 1)
        return 0;
    if(i == n-1 && j == m-1)
        return 1;

    int &ret = dp[i][j];
    if(~ret)
        return ret;

    long long tmp = (long long)solve(obstacleGrid, i + 1, j) + (long long)solve(obstacleGrid, i, j + 1);
    if(tmp > INT_MAX)
        return ret = 0;
    return ret = tmp;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    memset(dp, -1, sizeof(dp));
    n = obstacleGrid.size(), m = obstacleGrid[0].size();
    return solve(obstacleGrid, 0, 0);

    // Bottom-Up
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    // obstacle in start or end positions
    if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
        return 0;
    // long long is used for those dummy test cases that result in Int-overflow
    // if d + r > INT_MAX, mark the cell as non-reachable -1  hacky
    long long tmp;
    obstacleGrid[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0;--i)
    {
        for (int j = m - 1; j >= 0;--j)
        {
            if(i == n-1 && j == m-1)
                continue;
            // obstacle
            if(obstacleGrid[i][j] == 1)
            {
                obstacleGrid[i][j] = 0;
                continue;
            }
            long long d = 0, r = 0;
            if(i+1<n)
                d = obstacleGrid[i + 1][j];
            if(j+1 < m)
                r = obstacleGrid[i][j + 1];
            tmp = d + r;
            if(tmp > INT_MAX)
                obstacleGrid[i][j] = 0;
            else
                obstacleGrid[i][j] = tmp;
        }
    }
    return obstacleGrid[0][0];
}