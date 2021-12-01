#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums)
{
    int mx = 1;
    int cnt = 1;
    for (int i = 1; i < nums.size();++i)
    {
        if(nums[i] <= nums[i-1])
        {
            cnt = 1;
            continue;
        }
        cnt += nums[i] > nums[i - 1];
        mx = max(mx, cnt);
    }
    return mx;
}