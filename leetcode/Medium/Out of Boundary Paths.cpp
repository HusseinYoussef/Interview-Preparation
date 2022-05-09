#include <cstring>

using namespace std;

int mod = 1e9 + 7;
int dp[52][52][52];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int solve(int x, int y, int leftMoves, int m, int n)
{
    if(x < 0 || x >= m || y < 0 || y >= n)
        return 1;

    if(leftMoves == 0)
        return 0;

    int &ret = dp[x][y][leftMoves];
    if(~ret)
        return ret;

    ret = 0;
    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        ret += solve(nx, ny, leftMoves - 1, m, n);
        ret %= mod;
    }
    return ret;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    memset(dp, -1, sizeof(dp));
    return solve(startRow, startColumn, maxMove, m, n);
}