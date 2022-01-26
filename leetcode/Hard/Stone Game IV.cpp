#include <vector>
#include <cstring>

using namespace std;

int dp[2][100005];
// 0 -> Alice , 1 -> Bob
// O(N * sqrt(N))
int solve(bool player, int n)
{
    if(n == 0)
        return player;

    int &ret = dp[player][n];
    if(~ret)
        return ret;
    
    ret = player;
    for (int i = 1; i*i <= n;++i)
    {
        if(player == 0)
        {
            ret |= solve(!player, n - i*i);
            if(ret)
                break;
        }
        else
        {
            ret &= solve(!player, n - i*i);
            if(!ret)
                break;
        }
    }
    return ret;
}

bool winnerSquareGame(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(0, n);
}