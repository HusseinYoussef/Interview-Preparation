#include <vector>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for(int i = 0;i<m;++i)
    {
        for(int j = 0;j<n;++j)
        {
            int c = (j + k) % n, r = i;
            int shift = k - (n-1-j);
            if(shift >= 0)
                r = (i + ((shift + n - 1) / n)) % m;
            ans[r][c] = grid[i][j];
        }
    }
    return ans;
}
