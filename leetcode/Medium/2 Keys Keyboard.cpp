#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int dp[1005][1005];
int solve(int cur, int buffer, int n)
{
    if(cur == n)
        return 0;
    if(cur > n)
        return 1e7;

    int &ret = dp[cur][buffer];
    if(~ret)
        return ret;

    ret = 1e7;
    // paste
    if(buffer)
        ret = solve(cur + buffer, buffer, n) + 1;
    // copy and paste
    return ret = min(ret, solve(cur + cur, cur, n) + 2);
}

int minSteps(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(1, 0, n);
}