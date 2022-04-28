#include <vector>
#include <algorithm>

using namespace std;

void rec(vector<vector<int>> &ans, vector<int> &comb, vector<int> &arr, int idx, int sum)
{
    if(sum == 0)
    {
        ans.push_back(comb);
        return;
    }
    if(idx == arr.size())
        return;
    
    rec(ans, comb, arr, idx+1, sum);
    if(arr[idx] <= sum)
    {
        comb.push_back(arr[idx]);
        rec(ans, comb, arr, idx, sum-arr[idx]);
        comb.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& arr, int k)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int>comb;
    rec(ans, comb, arr, 0, k);
    return ans;
}