#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    if(obstacleGrid[n-1][m-1] == 1)
        return 0;
    // long long is used for those dummy test cases that results in int overflow
    // if d + r > INT_MAX, mark the cell as non-reachable -1  hacky
    long long tmp;
    obstacleGrid[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0;--i)
    {
        for (int j = m - 1; j >= 0;--j)
        {
            if(i == n-1 && j == m-1 || obstacleGrid[i][j] == -1)
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
                obstacleGrid[i][j] = -1;
            else
                obstacleGrid[i][j] = tmp;
        }
    }
    return obstacleGrid[0][0];
}