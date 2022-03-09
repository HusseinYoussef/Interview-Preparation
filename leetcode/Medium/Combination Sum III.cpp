#include <vector>

using namespace std;

void rec(vector<vector<int>> &ans, vector<int> &comb, int idx, int k, int n)
{
    if(k == 0 && n == 0)
    {
        ans.push_back(comb);
        return;
    }

    for(int i = idx;i<=9;++i)
    {
        if(i <= n && k > 0)
        {
            comb.push_back(i);
            rec(ans, comb, i+1, k-1, n-i);
            comb.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> comb;
    rec(ans, comb, 1, k, n);
    return ans;
}
