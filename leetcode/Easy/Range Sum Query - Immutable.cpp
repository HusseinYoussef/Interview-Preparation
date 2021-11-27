#include <iostream>
#include <vector>

using namespace std;

int pref[10005];
NumArray(vector<int>& nums)
{
    pref[0] = 0;
    for (int i = 1; i <= nums.size();++i)
    {
        pref[i] = pref[i - 1] + nums[i - 1];
    }
}

int sumRange(int left, int right)
{
    return pref[right+1] - pref[left];
}