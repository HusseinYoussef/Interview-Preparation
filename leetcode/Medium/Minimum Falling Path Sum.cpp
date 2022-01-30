#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[105][105];
int solve(vector<vector<int>>& matrix, int r, int c)
{
    if(r == n || c == n || c < 0)
        return 1e8;
    if(r == n-1)
        return matrix[r][c];

    int &ret = dp[r][c];
    if(~ret)
        return ret;

    return ret = min(solve(matrix, r + 1, c - 1), min(solve(matrix, r + 1, c), solve(matrix, r + 1, c + 1))) + matrix[r][c];
}

int minFallingPathSum(vector<vector<int>>& matrix)
{
    memset(dp, -1, sizeof(dp));
    n = matrix.size();
    int ans = 1e8;
    solve(matrix, 0, 0);
    for (int i = 0; i < n;++i)
        ans = min(ans, solve(matrix, 0, i));
    return ans;

    // Bottom-Up
    int n = matrix.size();
    int dp[105][105];
    for (int i = 0; i < n;++i)
        dp[n - 1][i] = matrix[n - 1][i];    
    for (int r = n - 2; r >= 0;--r)
    {
        for (int c = n - 1; c >= 0;--c)
        {
            int t1 = (c - 1 >= 0) ? dp[r + 1][c - 1] : 1e8;
            int t2 = (c + 1 < n) ? dp[r + 1][c + 1] : 1e8;
            dp[r][c] = min(dp[r + 1][c], min(t1, t2)) + matrix[r][c];
        }
    }
    int ans = 1e8;
    for (int i = 0; i < n;++i)
        ans = min(ans, dp[0][i]);
    return ans;
}