#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int mn = INT_MAX;
    for (int i = 0; i + 1 < n;++i)
        mn = min(mn, abs(arr[i] - arr[i + 1]));
    vector<vector<int>> ans;
    for (int i = 0; i + 1 < n;++i)
    {
        if(abs(arr[i]-arr[i+1]) == mn)
            ans.push_back({arr[i], arr[i + 1]});
    }
    return ans;
}