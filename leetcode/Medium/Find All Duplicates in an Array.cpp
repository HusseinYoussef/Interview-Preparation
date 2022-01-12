#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n;++i)
    {
        if(nums[abs(nums[i]) - 1] < 0)
            ans.push_back(abs(nums[i]));
        else
            nums[abs(nums[i]) - 1] *= -1;
    }
    return ans;

    // Use the 18th bit as bool vis array
    
    // int n = nums.size();
    // vector<int> ans;
    // for (int i = 0; i < n;++i)
    // {
    //     int val = (((1 << 17) - 1) & nums[i]);
    //     if((1 << 18) & nums[val-1])
    //         ans.push_back(val);
    //     else
    //         nums[val-1] |= (1 << 18);
    // }
    // return ans;
}