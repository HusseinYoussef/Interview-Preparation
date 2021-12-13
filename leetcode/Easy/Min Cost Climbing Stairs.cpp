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
        
    int n = cost.size();
    dp[n-1] = cost[n-1];
    dp[n-2] = cost[n-2];
    for(int i=n-3;i>=0;--i)
    {
        dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
    }
    return min(dp[0], dp[1]);
}
