#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> dp;
int solve(int n)
{
    if(n == 1)
        return 0;

    if(dp.find(n) != dp.end())
        return dp[n];

    if(n & 1)
        return dp[n] = min(solve(n/2), solve(n/2+1))+2;
    return dp[n] = solve(n/2)+1;
}

int integerReplacement(int n)
{
    return solve(n);
}
