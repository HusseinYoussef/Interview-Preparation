#include <iostream>
#include <vector>

using namespace std;

void rec(vector<vector<int>> &sets, vector<int> &nums, vector<int> s, int idx, int msk)
{
    if(idx == nums.size())
    {
        sets.push_back(s);
        return;
    }
    if(((1 << idx) & msk) == 0)
    {
        s.push_back(nums[idx]);
        rec(sets, nums, s, idx + 1, msk | (1 << idx));
        s.pop_back();
    }
    rec(sets, nums, s, idx + 1, msk);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    rec(ans, nums, {}, 0, 0);
    return ans;
}