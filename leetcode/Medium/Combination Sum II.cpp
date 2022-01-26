#include <vector>

using namespace std;

int n;
void rec(vector<vector<int>> &ans, vector<int>& candidates, vector<int>& freq, vector<int>& comb, int idx, int left)
{
    if(left == 0)
    {
        ans.push_back(comb);
        return;
    }
    for(int i = idx;i<n;++i)
    {
        if(candidates[i] <= left)
        {
            --freq[candidates[i]];
            comb.push_back(candidates[i]);
            rec(ans, candidates, freq, comb, i + (freq[candidates[i]] == 0), left - candidates[i]);
            ++freq[candidates[i]];
            comb.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    n = candidates.size();
    vector<int> freq(51, 0);
    for(int i = 0;i<n;++i)
    {
        freq[candidates[i]]++;
    }
    candidates.clear();
    for(int i =0;i<51;++i)
    {
        if(freq[i])
            candidates.push_back(i);
    }
    n = candidates.size();
    vector<vector<int>> ans;
    vector<int> comb;
    rec(ans, candidates, freq, comb, 0, target);
    return ans;
}
