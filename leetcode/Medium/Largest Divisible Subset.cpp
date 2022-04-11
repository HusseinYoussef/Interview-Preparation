#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int dp[1002];
int solve(vector<int>& nums, int idx, int pre)
{
    int &ret = dp[idx];
    if(~ret)
        return ret;


    for(int i = idx;i<n;++i)
    {
        if(nums[i] % pre == 0)
            ret = max(ret, solve(nums, i+1, nums[i]) + 1);
    }
    return ret;
}

vector<int> ans;
void build(vector<int>& path, vector<int>& nums, int idx, int pre, int len, int sz)
{
    for(int i = idx;i<n;++i)
    {
        if(dp[idx] == len && nums[i] % pre == 0 && path.size() < sz)
        {
            path.push_back(nums[i]);
            build(path, nums, i+1, nums[i], len-1, sz);
            if(path.size() == sz)
                break;
            path.pop_back();
        }
    }
}

vector<int> largestDivisibleSubset(vector<int>& nums)
{
    n = nums.size();
    sort(nums.begin(), nums.end());
    memset(dp, -1, sizeof(dp));
    int len = 1;
    for(int i = 0;i<n;++i)
    {
        dp[i] = max(dp[i], solve(nums, i, 1) + 1);
        len = max(len, dp[i]);
    }
    vector<int> path;
    for(int i = 0;i<n;++i)
    {
        build(path, nums, i, 1, len, len);
        if(path.size() == len)
            return path;
    }
    return path;
}
