
/*
    Problem Statement

    Write a function that takes in an array of positive integers and returns the
    maximum sum of non-adjacent elements in the array.
*/

#include <vector>
#include <cstring>
using namespace std;

int dp[1005];
// O(n) Time, O(n) Space
int solve(vector<int> &array, int idx)
{
    if(idx >= array.size())
        return 0;

    int &ret = dp[idx];
    if(~ret)
        return ret;

    return ret = max(solve(array, idx + 1), solve(array, idx + 2) + array[idx]);
}

int maxSubsetSumNoAdjacent(vector<int> array)
{
    memset(dp, -1, sizeof(dp));
    return solve(array, 0);

    // O(n) Space
    int dp[1005];
    memset(dp, 0, sizeof(dp));
    for (int idx = array.size() - 1; idx >= 0;--idx)
        dp[idx] = max(dp[idx + 1], dp[idx + 2] + array[idx]);
    return dp[0];


    // O(1) Space
    int nxt = 0, nxtnxt = 0;
    for (int idx = array.size() - 1; idx >= 0;--idx)
    {
        int cur = max(nxt, nxtnxt + array[idx]);
        nxtnxt = nxt;
        nxt = cur;
    }
    return nxt;
}