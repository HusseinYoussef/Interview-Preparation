#include <cstring>

using namespace std;

int mod = 1e9 + 7;
int dp[505][505];
int solve(int n, int p, int d)
{
    if(p == n && d == n)
        return 1;

    int &ret = dp[p][d];
    if(~ret)
        return ret;

    ret = 0;
    // Deliver : (p-d) options (items to deliver)
    if(d < p)
    {
        ret = ((long)(p-d) * solve(n, p, d+1)) % mod;
    }
    // Pick : (n-p) options (items to pick)
    if(p < n)
    {
        ret = (ret % mod + ((long)(n - p) * solve(n, p+1, d)) % mod) % mod;
    }
    return ret;
}
    
int countOrders(int n)
{       
    memset(dp, -1, sizeof(dp));
    return solve(n, 0, 0);

    // Bottom-Up
    int mod = 1e9 + 7;
    int dp[505][505];
    dp[n][n] = 1;
    for(int p = n; p>=0;--p)
    {
        for(int d = n-1;d>=0;--d)
        {
            dp[p][d] = 0;
            if(d < p)
                dp[p][d] = ((long)(p-d) * dp[p][d+1]) % mod;
            if(p < n)
                dp[p][d] = (dp[p][d] % mod + ((long)(n-p) * dp[p+1][d]) % mod) % mod;
        }
    }
    return dp[0][0];
}
