#include <vector>
#include <cstring>

using namespace std;
int n;
int mod = 1e9+7;
int dp[100005][3];
int solve(string &corridor, int idx, int seats)
{
    if (idx == n)
    {
        return seats == 2 ? 1 : 0;
    }

    int &ret = dp[idx][seats];
    if (~ret)
        return ret;

    ret = 0;
    if (seats == 2)
    {
        if (corridor[idx] == 'S')
            ret = ((ret % mod) + (solve(corridor, idx + 1, 1) % mod)) % mod;
        else
            ret = ((solve(corridor, idx + 1, 0) % mod) + (solve(corridor, idx + 1, seats) % mod)) % mod;
    }
    else
        ret = solve(corridor, idx + 1, seats + (corridor[idx] == 'S')) % mod;

    return ret;
}

int numberOfWays(string corridor)
{
    n = corridor.size();

    // memset(dp, -1, sizeof(dp));

    // bottom up
    int dp[100005][3];
    memset(dp, 0, sizeof(dp));
    dp[n][2] = 1;

    for (int idx = n-1;idx>=0;--idx)
    {
        for (int seats = 2;seats>=0;--seats)
        {
            int &ret = dp[idx][seats];

            ret = 0;
            if (seats == 2)
            {
                if (corridor[idx] == 'S')
                    ret = ((ret % mod) + (dp[idx+1][1] % mod)) % mod;
                else
                    ret = ((dp[idx+1][0] % mod) + (dp[idx+1][seats] % mod)) % mod;
            }
            else
                ret = dp[idx+1][seats + (corridor[idx] == 'S')] % mod;
        }
    }

    // bottom up rolling
    int dp[2][3];
    memset(dp, 0, sizeof(dp));
    dp[1][2] = 1;

    bool roll = 0;
    for (int idx = n-1;idx>=0;--idx)
    {
        for (int seats = 2;seats>=0;--seats)
        {
            int &ret = dp[roll][seats];

            ret = 0;
            if (seats == 2)
            {
                if (corridor[idx] == 'S')
                    ret = ((ret % mod) + (dp[!roll][1] % mod)) % mod;
                else
                    ret = ((dp[!roll][0] % mod) + (dp[!roll][seats] % mod)) % mod;
            }
            else
                ret = dp[!roll][seats + (corridor[idx] == 'S')] % mod;
        }
        roll = !roll;
    }

    return dp[!roll][0];
}
