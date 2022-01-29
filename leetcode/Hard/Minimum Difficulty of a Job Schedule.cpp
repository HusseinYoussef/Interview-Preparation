#include <vector>
#include <cstring>

using namespace std;

int n;
int dp[305][15];
int solve(vector<int>& jobDifficulty, int d, vector<int> &suf, int idx, int day)
{
    if(day == d)
        return suf[idx];

    int &ret = dp[idx][day];
    if(~ret)
        return ret;

    ret = 1e8;
    int mxdif = 0;
    for (int i = idx; i < n - (d - day);++i)
    {
        mxdif = max(mxdif, jobDifficulty[i]);
        ret = min(ret, solve(jobDifficulty, d, suf, i + 1, day + 1) + mxdif);
    }
    return ret;
}

int minDifficulty(vector<int>& jobDifficulty, int d)
{
    memset(dp, -1, sizeof(dp));
    n = jobDifficulty.size();
    if(n < d)
        return -1;
    vector<int> suf(n);
    int mx = 0;
    for (int i = n - 1; i >= 0;--i)
    {
        mx = max(mx, jobDifficulty[i]);
        suf[i] = mx;
    }
    return solve(jobDifficulty, d, suf, 0, 1);

    // int n = jobDifficulty.size();
    // if(n < d)
    //     return -1;
    // vector<int> suf(n);
    // int mx = 0;
    // for (int i = n - 1; i >= 0;--i)
    // {
    //     mx = max(mx, jobDifficulty[i]);
    //     suf[i] = mx;
    // }
    // int dp[305][15];
    // for (int i = 0; i < n;++i)
    //     dp[i][d] = suf[i];
    // for (int day = d - 1; day >= 1;--day)
    // {
    //     for (int idx = day - 1; idx < n - (d-day);++idx)
    //     {
    //         int mxdif = 0;
    //         dp[idx][day] = 1e8;
    //         for (int j = idx; j < n - (d - day);++j)
    //         {
    //             mxdif = max(mxdif, jobDifficulty[j]);
    //             dp[idx][day] = min(dp[idx][day], dp[j + 1][day + 1] + mxdif);
    //         }
    //     }
    // }
    // return dp[0][1];
}