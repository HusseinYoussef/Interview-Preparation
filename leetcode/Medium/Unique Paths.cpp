#include <vector>
#include <cstring>

using namespace std;

int dp[105][105];
int solve(int m,int n, int r, int c)
{
    if(r == m || c == n)
        return 0;
    if(r == m-1 && c == n-1)
        return 1;

    int &ret = dp[r][c];
    if(~ret)
        return ret;
    return ret = solve(m, n, r + 1, c) + solve(m, n, r, c + 1);
}

int uniquePaths(int m, int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(m, n, 0, 0);

    // Bottom-Up
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    // Base Case
    for (int i = 0; i < m;++i)
        dp[i][n - 1] = 1;
    for (int i = 0; i < n;++i)
        dp[m - 1][i] = 1;

    for (int i = m - 2; i >= 0;--i)
    {
        for (int j = n - 2; j >= 0;--j)
        {
            dp[i][j] += dp[i + 1][j] + dp[i][j + 1];
        }
    }
    return dp[0][0];
}