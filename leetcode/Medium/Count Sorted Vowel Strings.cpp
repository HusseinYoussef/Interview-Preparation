#include <vector>
#include <cstring>

using namespace std;

int dp[6][52];
int solve(int idx, int leftChars)
{
    if(leftChars == 0)
        return 1;

    int &ret = dp[idx][leftChars];
    if(~ret)
        return ret;

    ret = 0;
    for (int i = idx; i < 5;++i)
    {
        ret += solve(i, leftChars - 1);
    }
    return ret;
}

int countVowelStrings(int n)
{
    memset(dp, -1, sizeof(dp));
    return solve(0, n);

    // Bottom Up ~ O(n) Space
    int dp[6][52];
    memset(dp, 0, sizeof(dp));
    // Base Case
    for (int i = 0; i < 6;++i)
        dp[i][0] = 1;
    
    for (int leftChars = 1; leftChars <= n; ++leftChars)
    {
        for (int idx = 0; idx < 5;++idx)
        {
            dp[idx][leftChars] = 0;
            for (int i = idx; i < 5;++i)
            {
                dp[idx][leftChars] += dp[i][leftChars - 1];
            }
        }
    }
    return dp[0][n];

    // rolling ~ O(1) Space
    int dp[6][2];
    memset(dp, 0, sizeof(dp));
    // Base Case
    for (int i = 0; i < 6;++i)
        dp[i][0] = 1;

    bool roll = 1;
    for (int leftChars = 1; leftChars <= n; ++leftChars)
    {
        for (int idx = 0; idx < 5;++idx)
        {
            dp[idx][roll] = 0;
            for (int i = idx; i < 5;++i)
            {
                dp[idx][roll] += dp[i][!roll];
            }
        }
        roll = !roll;
    }
    return dp[0][!roll];
}