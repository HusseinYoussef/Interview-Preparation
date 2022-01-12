#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();
    // Bottom-Up Dp
    for (int i = n - 1; i >= 0;--i)
    {
        for (int j = m - 1; j >= 0;--j)
        {
            if(i == n-1 && j == m-1)
                continue;
            int d = INT_MAX, r = INT_MAX;
            if(i+1 < n)
                d = grid[i + 1][j];
            if(j+1 < m)
                r = grid[i][j + 1];
            grid[i][j] += min(d, r);
        }
    }
    return grid[0][0];
}