#include <vector>

using namespace std;

void rec(vector<vector<int>> &ans, vector<int> &comb, int st,  int n, int k)
{
    if(comb.size() == k)
    {
        ans.push_back(comb);
        return;
    }
    for (int i = st; i <= n;++i)
    {
        comb.push_back(i);
        rec(ans, comb, i + 1, n, k);
        comb.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> comb;
    rec(ans, comb, 1, n, k);
    return ans;
}