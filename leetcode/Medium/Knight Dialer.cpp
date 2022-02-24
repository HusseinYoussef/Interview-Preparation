#include <cstring>

using namespace std;

int mod = 1e9 + 7;
int r = 4, c = 3;
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {1, -1, -2, -2, -1, 1, 2, 2};
int dp[5005][5][5];

int solve(int left, int x, int y)
{
    if(left == 0)
        return 1;

    int &ret = dp[left][x][y];
    if(~ret)
        return ret;

    ret = 0;
    for (int i = 0; i < 8;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c && (nx != 3 || ny == 1))
        {
            ret = (ret % mod + solve(left - 1, nx, ny) % mod) % mod;
        }
    }
    return ret;
}

int knightDialer(int n)
{
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < r;++i)
    {
        for (int j = 0; j < c;++j)
        {
            if(i != 3 || j == 1)
            {
                ans = (ans % mod + solve(n - 1, i, j) % mod) % mod;
            }
        }
    }
    return ans;

    // Bottom Up O(N) Space
    int mod = 1e9 + 7;
    int r = 4, c = 3;
    int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dy[8] = {1, -1, -2, -2, -1, 1, 2, 2};
    int dp[5005][5][5];

    // Base Case
    for (int i = 0; i < 5;++i)
        for (int j = 0; j < 5;++j)
            dp[0][i][j] = 1;
    
    for (int left = 1; left <= n;++left)
    {
        for (int x = 0; x < r;++x)
        {
            for (int y = 0; y < c;++y)
            {
                dp[left][x][y] = 0;
                for (int i = 0; i < 8;++i)
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx >= 0 && nx < r && ny >= 0 && ny < c && (nx != 3 || ny == 1))
                    {
                        dp[left][x][y] = (dp[left][x][y] % mod + dp[left - 1][nx][ny] % mod) % mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < r;++i)
    {
        for (int j = 0; j < c;++j)
        {
            if(i != 3 || j == 1)
            {
                ans = (ans % mod + dp[n-1][i][j] % mod) % mod;
            }
        }
    }
    return ans;


    // Bottom Up O(1) Space - Rolling
    int mod = 1e9 + 7;
    int r = 4, c = 3;
    int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dy[8] = {1, -1, -2, -2, -1, 1, 2, 2};
    int dp[2][5][5];

    // Base Case
    for (int i = 0; i < 5;++i)
        for (int j = 0; j < 5;++j)
            dp[0][i][j] = 1;

    bool roll = 1;
    for (int left = 1; left <= n;++left)
    {
        for (int x = 0; x < r;++x)
        {
            for (int y = 0; y < c;++y)
            {
                dp[roll][x][y] = 0;
                for (int i = 0; i < 8;++i)
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx >= 0 && nx < r && ny >= 0 && ny < c && (nx != 3 || ny == 1))
                    {
                        dp[roll][x][y] = (dp[roll][x][y] % mod + dp[!roll][nx][ny] % mod) % mod;
                    }
                }
            }
        }
        roll = !roll;
    }
    int ans = 0;
    for (int i = 0; i < r;++i)
    {
        for (int j = 0; j < c;++j)
        {
            if(i != 3 || j == 1)
            {
                ans = (ans % mod + dp[!roll][i][j] % mod) % mod;
            }
        }
    }
    return ans;
}