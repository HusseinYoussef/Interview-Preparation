#include <vector>

using namespace std;

void rec(vector<vector<int>>& grid, 
        vector<pair<int, int>>& zeros,
        vector<pair<int, int>>& filled, int idx, int total, int &ans)
{
    if (idx == zeros.size())
    {
        ans = min(ans, total);
        return;
    }

    for (int i = 0;i<filled.size();++i)
    {
        int x = filled[i].first, y = filled[i].second;
        if(grid[x][y] > 1)
        {
            int dist = abs(zeros[idx].first - x) + abs(zeros[idx].second - y);
            grid[x][y]--;
            rec(grid, zeros, filled, idx+1, total + dist, ans);
            grid[x][y]++;
        }
    }
}

int minimumMoves(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size();

    vector<pair<int, int>> zeros, filled;
    for (int i = 0;i<n;++i)
    {
        for (int j = 0;j<m;++j)
        {
            if (grid[i][j] == 0)
            {
                zeros.push_back({i, j});
            }
            else if (grid[i][j] > 1)
            {
                filled.push_back({i, j});
            }
        }
    }

    int ans = 1e8;
    rec(grid, zeros, filled, 0, 0, ans);
    return ans;
}
