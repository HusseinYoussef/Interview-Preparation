#include <iostream>
#include <cstring>
using namespace std;

int dp[50];

int solve(int n)
{
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;

    int &ret = dp[n];
    if(~ret)
        return ret;

    return ret = solve(n - 1) + solve(n - 2);
}

int climbStairs(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(n);
}

int main()
{
    cout << climbStairs(4);
    return 0;
}