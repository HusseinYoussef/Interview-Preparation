#include <vector>
#include <cstring>

using namespace std;

int n, m;
int ans = 0;
// dp[i][j]: max depth from starting from cell i,j
int dp[205][205];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
// get max depth
int dfs(vector<vector<int>>& matrix, int x, int y, int pre)
{
    if(x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] <= pre)
        return 0;

    int &ret = dp[x][y];
    if(~ret)
        return ret;

    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        ret = max(ret, dfs(matrix, nx, ny, matrix[x][y]) + 1);
    }
    return ret;
}

int longestIncreasingPath(vector<vector<int>>& matrix)
{
    n = matrix.size(), m = matrix[0].size();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(dp[i][j] == -1)
                dfs(matrix, i, j, -1);
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}