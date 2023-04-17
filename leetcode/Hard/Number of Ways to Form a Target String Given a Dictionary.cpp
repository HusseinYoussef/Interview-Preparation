#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[1005][1005];
int mod = 1e9 + 7;
int solve(vector<vector<int>> &freq, string &target, int idx, int k)
{
    if (idx == target.size())
        return 1;

    if (k >= n)
      return 0;

    int &ret = dp[idx][k];
    if (~ret)
        return ret;

    ret = 0;
    int c = target[idx] - 'a';
    ret = (solve(freq, target, idx, k + 1) % mod + ((solve(freq, target, idx + 1, k + 1) % mod) * ((long long)freq[k][c] % mod)) % mod) % mod; 
    return ret;
}

int numWays(vector<string>& words, string target)
{
    n = words[0].size(); 
    vector<vector<int>> freq(n, vector<int> (26, 0));

    for(int i = 0;i<words.size();++i)
    {
        for(int j = 0;j<words[i].size();++j)
        {
            freq[j][words[i][j] - 'a']++;
        }
    }
    // memset(dp, -1, sizeof(dp));
    // return solve(freq, target, 0, 0);

    // Bottom up
    int dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    for(int i = 0;i<1005;++i)
      dp[target.size()][i] = 1;

    for (int idx = target.size() - 1;idx>=0;--idx)
    {
        int c = target[idx] - 'a';
        for (int k = n - 1;k>=0;--k)
        {
            dp[idx][k] = (dp[idx][k+1] % mod + ((dp[idx+1][k+1] % mod) * ((long long)freq[k][c] % mod)) % mod) % mod; 
        }
    }
    return dp[0][0];
}
