#include <cstring>

using namespace std;

double champagneTower(int poured, int query_row, int query_glass)
{
    double dp[105][105];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = poured;
    for(int i = 0;i<=100;++i)
    {
        for(int j = 0;j<=i;++j)
        {
            if(dp[i][j] > 1)
            {
                double over = dp[i][j] - 1;
                dp[i+1][j] += over / 2;
                dp[i+1][j+1] += over / 2;
            }
            if(query_row == i && query_glass == j)
                    return min(dp[i][j], 1.0);
        }
    }
    return 0;
}
