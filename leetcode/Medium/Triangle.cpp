#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[205][205];
int solve(vector<vector<int>>& triangle, int row, int idx)
{
    if(row == n-1)
        return triangle[row][idx];

    int &ret = dp[row][idx];
    if(~ret)
        return ret;

    return ret = min(solve(triangle, row+1, idx), solve(triangle, row+1, idx+1)) + triangle[row][idx];
}

int minimumTotal(vector<vector<int>>& triangle)
{
    n = triangle.size();
    memset(dp, -1, sizeof(dp));
    return solve(triangle, 0,0);

    // O(N^2) Space - Bottom Up DP
    int n = triangle.size();
    int dp[205][205];
    for(int i = 0;i<n;++i)
        dp[n-1][i] = triangle[n-1][i];
    for(int row = n-2; row>=0; --row)
    {
        for(int idx = 0;idx<=row;++idx)
        {
            dp[row][idx] = min(dp[row+1][idx], dp[row+1][idx+1]) + triangle[row][idx];
        }
    }
    return dp[0][0];

    // O(N) Space - Bottom Up DP with Rolling
    int n = triangle.size();
    int dp[2][205];
    for(int i = 0;i<n;++i)
        dp[1][i] = triangle[n-1][i];

    bool roll = 0;
    for(int row = n-2; row>=0; --row)
    {
        for(int idx = 0;idx<=row;++idx)
        {
            dp[roll][idx] = min(dp[!roll][idx], dp[!roll][idx+1]) + triangle[row][idx];
        }
        roll = !roll;
    }
    return dp[!roll][0];

    // O(1) Space - Bottom Up using input as DP
    int n = triangle.size();
    for(int row = n-2; row>=0; --row)
    {
        for(int idx = 0;idx<=row;++idx)
        {
            triangle[row][idx] = min(triangle[row+1][idx], triangle[row+1][idx+1]) + triangle[row][idx];
        }
    }
    return triangle[0][0];
}
