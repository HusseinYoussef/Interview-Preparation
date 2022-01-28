#include <vector>
#include <cstring>

using namespace std;

int n, m;
int ans = 0;
int dp[305][305];
int solve(vector<vector<char>>& matrix, int i, int j)
{
    if(i == n || j == m)
        return 0;

    int &ret = dp[i][j];
    if(~ret)
        return ret;

    int len = min(solve(matrix, i + 1, j), min(solve(matrix, i, j + 1), solve(matrix, i + 1, j + 1)));
    if(matrix[i][j] == '1')
    {
        ans = max(ans, len + 1);
        return ret = len + 1;
    }
    return ret = 0;
}

int maximalSquare(vector<vector<char>>& matrix)
{
    n = matrix.size(), m = matrix[0].size();
    memset(dp, -1, sizeof(dp));
    int s = solve(matrix, 0, 0);
    return ans * ans;

    // Bottom-Up
    // int n = matrix.size(), m = matrix[0].size();
    // int dp[305][305];
    // for (int i = 0; i <= n;++i)
    //     dp[i][m] = 0;
    // for (int i = 0; i <= m;++i)
    //     dp[n][i] = 0;
    // int ans = 0;
    // for (int i = n - 1; i >= 0;--i)
    // {
    //     for (int j = m - 1; j >= 0;--j)
    //     {
    //         if(matrix[i][j] == '1')
    //             dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
    //         else
    //             dp[i][j] = 0;
    //         ans = max(ans, dp[i][j]);
    //     }
    // }
    // return ans * ans;
}