#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> twoSum(vector<int> nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size();++i)
    {
        if(mp[target - nums[i]])
        {
            ans.push_back(i);
            ans.push_back(mp[target - nums[i]]-1);
            return ans;
        }
        mp[nums[i]] = i+1;
    }
}


int main()
{
    vector<int> vec = {3,2,3};
    vector<int> ans = twoSum(vec, 6);
    for(auto i :ans)
    {
        cout << i << endl;
    }
    return 0;
}