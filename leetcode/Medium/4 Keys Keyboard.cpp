#include <iostream>
#include <map>

using namespace std;

map<pair<pair<int, int>, int>, int> dp;
int solve(int cur, int buffer, int n)
{
    if(n == 0)
        return 0;
    if(n < 0)
        return -1e8;
    
    if(dp.find({{cur, buffer}, n}) != dp.end())
        return dp[{{cur, buffer}, n}];

    int &ret = dp[{{cur, buffer}, n}];
    ret = -1e8;

    // paste is always better than just printing 1 char
    if(buffer)
        ret = solve(cur + buffer, buffer, n - 1);
    else
        ret = solve(cur + 1, buffer, n - 1);
    // copy and paste
    if(cur)
        ret = max(ret, solve(cur + cur, cur, n - 3));
    return ret;
}

int maxA(int N)
{
    return solve(0, 0, N);
}