#include <iostream>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target)
{
    auto idx = lower_bound(nums.begin(), nums.end(), target);
    if(idx == nums.end() || *idx != target)
        return -1;
    return idx - nums.begin();
}