#include <cstring>

double dp[26][26][105];
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {1, -1, -2, -2, -1, 1, 2, 2};

double solve(int n, int r, int c, int k)
{
    if(r < 0 || r >= n || c < 0 || c >= n)
        return 0;
    if(k == 0)
        return 1;

    double &ret = dp[r][c][k];
    if(ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < 8;++i)
        ret += 0.125 * solve(n, r + dx[i], c + dy[i], k - 1);
    return ret;
}

double knightProbability(int n, int k, int row, int column)
{
    // for (int i = 0; i < 26;++i)
    //     for (int j = 0; j < 26;++j)
    //         for (int z = 0; z < 105;++z)
    //             dp[i][j][z] = -1;
    // return solve(n, row, column, k);

    // Bottom Up
    double dp[26][26][105];
    int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dy[8] = {1, -1, -2, -2, -1, 1, 2, 2};

    for (int i = 0; i < 26;++i)
        for (int j = 0; j < 26;++j)
            dp[i][j][0] = 1;

    for (int left = 1; left <= k;++left)
    {
        for (int r = 0; r < n;++r)
        {
            for (int c = 0; c < n;++c)
            {
                dp[r][c][left] = 0;
                for (int i = 0; i < 8;++i)
                {
                    int nr = r + dx[i], nc = c + dy[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n)
                        dp[r][c][left] += 0.125 * dp[nr][nc][left - 1];
                }
            }
        }
    }
    return dp[row][column][k];
}