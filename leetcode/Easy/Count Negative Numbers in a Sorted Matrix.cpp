#include <iostream>
#include <vector>

using namespace std;

int countNegatives(vector<vector<int>>& grid)
{
    // O(n + m)
    int n = grid.size(), m = grid[0].size();
    int curx = n-1, cury = 0;
    int ans = 0;
    while(curx >= 0 && cury < m)
    {
        if(grid[curx][cury] < 0)
        {
            ans += m - cury;
            --curx;
        }
        else
            ++cury;
    }
    return ans;
}
