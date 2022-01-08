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
    int i;
    for (i = idx; i < nums.size();++i)
    {
        if (((1 << i) & msk) == 0)
        {
            s.push_back(nums[i]);
            rec(sets, nums, s, i + 1, msk | (1 << i));
            s.pop_back();
        }
    }
    rec(sets, nums, s, i, msk);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    rec(ans, nums, {}, 0, 0);
    return ans;
}