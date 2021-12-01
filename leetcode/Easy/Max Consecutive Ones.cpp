#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int mx = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size();++i)
    {
        if(nums[i] == 0)
            cnt = 0;
        cnt += nums[i] & 1;
        mx = max(mx, cnt);
    }
    return mx;
}