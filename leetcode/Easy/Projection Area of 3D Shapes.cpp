#include <iostream>
#include <vector>

using namespace std;

int projectionArea(vector<vector<int>>& grid)
{
    int cnt =0;
    int ans=0;
    for(int i=0;i<grid.size();++i)
    {
        int mx = 0;
        for(int j =0;j<grid[0].size();++j)
        {
            cnt += grid[i][j] > 0;
            mx = max(mx, grid[i][j]);
        }
        ans += mx;
    }
    for(int i=0;i<grid[0].size();++i)
    {
        int mx = 0;
        for(int j =0;j<grid.size();++j)
        {
            mx = max(mx, grid[j][i]);
        }
        ans += mx;
    }
    return ans + cnt;
}
