#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i < n + 1;++i)
    {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}

int main()
{
    return 0;
}