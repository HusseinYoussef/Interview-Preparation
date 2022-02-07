#include <iostream>
#include <vector>

using namespace std;

void rec(vector<vector<int>> &sets, vector<int> &nums, vector<int> &s, int idx)
{
    if(idx == nums.size())
    {
        sets.push_back(s);
        return;
    }
    rec(sets, nums, s, idx + 1);
    s.push_back(nums[idx]);
    rec(sets, nums, s, idx + 1);
    s.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> s;
    rec(ans, nums, s, 0);
    return ans;
}
