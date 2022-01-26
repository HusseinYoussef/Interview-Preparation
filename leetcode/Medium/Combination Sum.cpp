#include <iostream>
#include <vector>

using namespace std;

int n;
void rec(vector<vector<int>> &ans, vector<int>& candidates, vector<int>& comb, int idx, int left)
{
    if(left == 0)
    {
        ans.push_back(comb);
        return;
    }

    for(int i = idx; i<n;++i)
    {
        if(candidates[i] <= left)
        {
            comb.push_back(candidates[i]);
            rec(ans, candidates, comb, i, left-candidates[i]);
            comb.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    n = candidates.size();
    vector<vector<int>> ans;
    vector<int> comb;
    rec(ans, candidates, comb, 0, target);
    return ans;
}
