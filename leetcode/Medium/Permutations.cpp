#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> ans;
vector<int> perm;
void rec(vector<int>& nums, int msk, int taken=0)
{
    if(taken == n)
    {
        ans.push_back(perm);
        return;
    }

    for (int i = 0; i < n;++i)
    {
        if(((1<<i) & msk) == 0)
        {
            perm.push_back(nums[i]);
            rec(nums, msk | (1 << i), taken + 1);
            perm.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    n = nums.size();
    rec(nums, 0, 0);
    return ans;

    // sort(nums.begin(), nums.end());
    // do
    // {
    //     ans.push_back(nums);
    // } while (next_permutation(nums.begin(), nums.end()));
    // return ans;
}