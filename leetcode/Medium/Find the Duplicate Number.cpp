#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums)
{
    // Move each element to its right place O(N)
    for (int i = 0; i < nums.size();++i)
    {
        while(nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);

    }
    return nums[nums.size() - 1];
}