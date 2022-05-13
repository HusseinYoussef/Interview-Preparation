#include <cstring>

using namespace std;

int dp[1005];
int solve(int height, int maxSteps, int step)
{
	if(step > height)
		return 0;
	if(step == height)
		return 1;
	
	int &ret = dp[step];
	if(~ret)
		return ret;
	ret = 0;
	for(int i = 1;i<=maxSteps;++i)
	{
		ret += solve(height, maxSteps, step+i);
	}
	return ret;
}

int staircaseTraversal(int height, int maxSteps)
{
    memset(dp, -1, sizeof(dp));
    return solve(height, maxSteps, 0);

    // O(n) sliding window + Bottom Up DP
	int dp[1100];
	memset(dp, 0, sizeof(dp));
	dp[height] = 1;
	int winSum = 1;
	for(int step = height-1;step>=0;--step)
	{
		dp[step] = winSum;
		winSum += dp[step] - dp[step+maxSteps];
	}
	return dp[0];
}