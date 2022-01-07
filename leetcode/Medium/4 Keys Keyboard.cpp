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
    // return solve(0, 0, N);

    int dp[N + 1];
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        // press [ A ]
        dp[i] = dp[i - 1] + 1;
        for (int j = 2; j < i; j++)
        {
            // [Ctrl-A] & [Ctrl-C] -> dp[j-2], Paste i-j times
            // There are { dp[j-2] * (i-j+1) }number of 'A' on the screen => dp[j-2] + dp[j-2] * (i-j) => take dp[j-2] as common factor
            dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
        }
    }
    // What is the maximum number of 'A' after N keystrokes?
    return dp[N];
}