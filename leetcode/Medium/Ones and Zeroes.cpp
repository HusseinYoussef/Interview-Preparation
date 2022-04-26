#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int sz;
int dp[602][102][102];
int solve(vector<string>& strs, vector<int> &zeros, int idx, int lftzeros, int lftones)
{
    if((lftzeros == 0 && lftones == 0) || idx == sz)
        return 0;

    int &ret = dp[idx][lftzeros][lftones];
    if(~ret)
        return ret;

    ret = 0;
    int zs = zeros[idx], os = strs[idx].size() - zeros[idx];
    if(zs <= lftzeros && os <= lftones)
        ret = solve(strs, zeros, idx + 1, lftzeros - zs, lftones - os) + 1;
    return ret = max(ret, solve(strs, zeros, idx + 1, lftzeros, lftones));
}

int findMaxForm(vector<string>& strs, int m, int n)
{
    sz = strs.size();
    vector<int> zeros(strs.size() + 1, 0);
    for (int i = 0; i < strs.size(); ++i)
    {
        int cnt = 0;
        for (int j = 0; j < strs[i].size();++j)
        {
            cnt += strs[i][j] == '0';
        }
        zeros[i] = cnt;
    }
    
    memset(dp, -1, sizeof(dp));
    return solve(strs, zeros, 0, m, n);

    // **** Bottom Up ****
    int dp[602][102][102];
    memset(dp, 0, sizeof(dp));
    for (int idx = sz - 1; idx >= 0;--idx)
    {
        for (int lftzeros = 0; lftzeros <= m;++lftzeros)
        {
            for (int lftones = 0; lftones <= n;++lftones)
            {
                int zs = zeros[idx], os = strs[idx].size() - zeros[idx];
                if(zs <= lftzeros && os <= lftones)
                    dp[idx][lftzeros][lftones] = dp[idx + 1][lftzeros - zs][lftones - os] + 1;
                dp[idx][lftzeros][lftones] = max(dp[idx][lftzeros][lftones], dp[idx + 1][lftzeros][lftones]);
            }
        }
    }
    return dp[0][m][n];

    // **** Rolling ****
    int dp[2][102][102];
    memset(dp, 0, sizeof(dp));
    bool roll = 0;
    for (int idx = sz - 1; idx >= 0;--idx)
    {
        for (int lftzeros = 0; lftzeros <= m;++lftzeros)
        {
            for (int lftones = 0; lftones <= n;++lftones)
            {
                int zs = zeros[idx], os = strs[idx].size() - zeros[idx];
                if(zs <= lftzeros && os <= lftones)
                    dp[roll][lftzeros][lftones] = dp[!roll][lftzeros - zs][lftones - os] + 1;
                dp[roll][lftzeros][lftones] = max(dp[roll][lftzeros][lftones], dp[!roll][lftzeros][lftones]);
            }
        }
        roll = !roll;
    }
    return dp[!roll][m][n];
}