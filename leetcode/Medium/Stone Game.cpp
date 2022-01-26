#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[2][505][505];
int solve(vector<int>& piles, bool player, int l, int r)
{
    if(r < l)
        return 0;

    int &ret = dp[player][l][r];
    if(~ret)
        return ret;

    if(player == 0)
        return ret = max(solve(piles, 1, l+1, r) + piles[l], solve(piles, 1, l, r-1) + piles[r]);
    return ret = min(solve(piles, 0, l+1, r), solve(piles, 0, l, r-1));
}

bool stoneGame(vector<int>& piles)
{
    int sum = 0;
    n = piles.size();
    for(int i = 0;i<n;++i)
        sum += piles[i];
    memset(dp, -1, sizeof(dp));
    int ans = solve(piles, 0, 0, n-1);
    return ans > (sum - ans);
}
