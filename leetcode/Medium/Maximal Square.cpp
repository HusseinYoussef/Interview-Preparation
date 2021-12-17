#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < m;++i)
        ans |= dp[i][n-1] = matrix[i][n-1] - '0';
    for (int i = 0; i < n;++i)
        ans |= dp[m-1][i] = matrix[m-1][i] - '0';

    // dp[i][j] = size of square with i, j at top-left element
    for (int i = m - 2; i >= 0;--i)
    {
        for (int j = n - 2; j >= 0;--j)
        {
            if(matrix[i][j] - '0')
                dp[i][j] = min(dp[i][j + 1], min(dp[i + 1][j], dp[i + 1][j + 1])) + 1;
            else
                dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans*ans;
}