#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int repeatedNTimes(vector<int>& nums)
{
    unordered_map<int, bool> mp;
    for (int i = 0; i < nums.size();++i)
    {
        if(mp[nums[i]])
            return nums[i];
        mp[nums[i]] = 1;
    }
    return 0;
}