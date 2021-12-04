#include <iostream>
#include <vector>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
{
    vector<int> mxh(grid.size());
    vector<int> mxv(grid[0].size());
    for (int i = 0; i < grid.size();++i)
    {
        int mx = 0;
        for (int j = 0; j < grid[0].size();++j)
            mx = max(mx, grid[i][j]);
        mxh[i] = mx;
    }
    for (int i = 0; i < grid[0].size();++i)
    {
        int mx = 0;
        for (int j = 0; j < grid.size();++j)
            mx = max(mx, grid[j][i]);
        mxv[i] = mx;
    }
    int sum = 0;
    for (int i = 0; i < grid.size();++i)
    {
        for (int j = 0; j < grid[0].size();++j)
        {
            sum += min(mxh[i], mxv[j]) - grid[i][j];
        }
    }
    return sum;
}