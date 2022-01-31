#include <vector>
#include <cstring>

using namespace std;

int n;
int mx = 366;
int dp[370];
// Buy Tickets only on days that we need to travel on
int solve(vector<bool>& mp, vector<int>& costs, int day)
{
    if(day > 365)
        return 0;

    int &ret = dp[day];
    if (~ret)
        return ret;

    if(mp[day] == 0)
        return ret = solve(mp, costs, day + 1);

    ret = solve(mp, costs, min(mx, day + 1)) + costs[0];
    ret = min(ret, solve(mp, costs, min(mx, day + 7)) + costs[1]);
    return ret = min(ret, solve(mp, costs, min(mx, day + 30)) + costs[2]);
}

int mincostTickets(vector<int>& days, vector<int>& costs)
{
    memset(dp, -1, sizeof(dp));
    n = days.size();
    vector<bool> mp(370, 0);
    for (int i = 0; i < n;++i)
        mp[days[i]] = 1;
    return solve(mp, costs, 1);

    // Bottom-Up
    int n = days.size(), mx = 366;
    vector<bool> mp(370, 0);
    for (int i = 0; i < n;++i)
        mp[days[i]] = 1;
    int dp[370];
    memset(dp, 0, sizeof(dp));
    for (int day = 365; day >= 0;--day)
    {
        if(mp[day])
        {
            dp[day] = dp[min(mx, day + 1)] + costs[0];
            dp[day] = min(dp[day], dp[min(mx, day + 7)] + costs[1]);
            dp[day] = min(dp[day], dp[min(mx, day + 30)] + costs[2]);
        }
        else
            dp[day] = dp[day + 1];
    }
    return dp[0];
}