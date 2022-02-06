#include <vector>
#include <algorithm>

using namespace std;

int n;
void rec(vector<vector<int>> &ans, vector<int> &nums, vector<int> &perm)
{
    if(perm.size() == n)
    {
       ans.push_back(perm);
       return;
    }
    // consider only unique numbers as candidates ~ can also be done using a map/freq arr instead of sorting
    for(int i = 0;i<n;++i)
    {
        if(nums[i] == 15 || (i+1 < n && nums[i] == nums[i+1]))
            continue;
        int tmp = nums[i];
        perm.push_back(nums[i]);
        // some invalid value
        nums[i] = 15;
        rec(ans, nums, perm);
        perm.pop_back();
        nums[i] = tmp;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> perm = {};
    rec(ans, nums, perm);
    return ans;
}
