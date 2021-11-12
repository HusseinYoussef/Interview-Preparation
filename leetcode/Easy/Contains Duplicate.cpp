#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsDuplicate(vector<int>& nums)
{
    unordered_map<int, bool> mp;
    for (int i = 0; i < nums.size();++i)
    {
        if(mp[nums[i]])
            return true;
        mp[nums[i]] = 1;
    }
    return false;
}

int main()
{
    return 0;
}