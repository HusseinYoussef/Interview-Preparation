
/*
    Problem Statement

    You're given two positive integers representing the width and height of a
    grid-shaped, rectangular graph. Write a function that returns the number of
    ways to reach the bottom right corner of the graph when starting at the top
    left corner. Each move you take must either go down or right. In other words,
    you can never move up or left in the graph.
*/

#include <vector>
#include <cstring>
using namespace std;

int dp[105][105];
int solve(int width, int height, int x, int y)
{
    if(x < 0 || x == height || y < 0 || y == width)
        return 0;
    
    if(x == height-1 && y == width -1)
        return 1;

    int &ret = dp[x][y];
    if(~ret)
        return ret;

    return ret = solve(width, height, x + 1, y) + solve(width, height, x, y + 1);
}

int numberOfWaysToTraverseGraph(int width, int height)
{
    memset(dp, -1, sizeof(dp));
    return solve(width, height, 0, 0);

    // Bottom Up
    vector<vector<int>> dp(height, vector<int>(width, 0));
    for (int i = 0; i < width;++i)
        dp[height - 1][i] = 1;
    for (int i = 0; i < height;++i)
        dp[i][width - 1] = 1;

    for (int x = height - 1; x >= 0;--x)
    {
        for (int y = width - 1; y >= 0;--y)
        {
            dp[x][y] = dp[x + 1][y] + dp[x][y + 1];
        }
    }
    return dp[0][0];

    // Rolling
    vector<vector<int>> dp(2, vector<int>(width, 0));
    for (int i = 0; i < width;++i)
        dp[1][i] = 1;
		dp[0][width - 1] = 1;

		bool roll = 0;
    for (int x = height - 2; x >= 0;--x)
    {
        for (int y = width - 2; y >= 0;--y)
        {
            dp[roll][y] = dp[!roll][y] + dp[roll][y + 1];
        }
			roll = !roll;
    }
    return dp[!roll][0];
}
