#include <iostream>
#include <vector>

using namespace std;

int dp[1005];
int solve(vector<int>& cost, int idx)
{
    if(idx == cost.size())
        return 0;
    if(idx > cost.size())
        return 1e7;

    int &ret = dp[idx];
    if(~ret)
        return ret;
    return ret = min(solve(cost, idx+1), solve(cost, idx+2)) + cost[idx];

}
int minCostClimbingStairs(vector<int>& cost)
{
//  memset(dp, -1, sizeof(dp));
//  solve(cost, 0);
//  return min(dp[0], dp[1]);
        
    int dp[1002];
    int n = cost.size();
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2;i<=n;++i)
    {
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }
    return dp[n];
}
