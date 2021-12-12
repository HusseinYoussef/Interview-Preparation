#include <iostream>
#include <vector>

using namespace std;

vector<int> findErrorNums(vector<int>& nums)
{
    vector<int>ans(2);
    for(int i =0;i<nums.size();++i)
    {
        int idx = abs(nums[i]) - 1;
        if(nums[idx] < 0)           // duplicate element
            ans[0] = abs(nums[i]);
        else
            nums[idx] = -1*nums[idx];
    }
    for(int i =0;i<nums.size();++i)
    {
        if(nums[i] > 0)
            ans[1] = i+1;
    }
    return ans;
}
