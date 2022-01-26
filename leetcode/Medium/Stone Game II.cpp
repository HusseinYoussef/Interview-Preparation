#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[2][105][105];
// O(N^3)
int solve(vector<int>& piles, bool player, int idx, int m)
{
    if(idx == n)
        return 0;

    int &ret = dp[player][idx][m];
    if(~ret)
        return ret;
    int sum = 0;
    if(player == 0)
        ret = 0;
    else
        ret = 1e8;
    for(int i = idx; i < min(idx + 2*m, n);++i)
    {
        sum += piles[i];
        if(player == 0)
            ret = max(ret, solve(piles, 1, i+1, min(n, max(i-idx+1, m))) + sum);
        else                
            ret = min(ret, solve(piles, 0, i+1, min(n, max(i-idx+1, m))));
    }
    return ret;
}

int stoneGameII(vector<int>& piles)
{
    n = piles.size();
    memset(dp, -1, sizeof(dp));
    return solve(piles, 0, 0, 1);
}
