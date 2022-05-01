#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks)
{
    int n = tasks.size();
    vector<pair<int, int>> tmp;
    for (int i = 0; i < n;++i)
        tmp.push_back({tasks[i], i});
    sort(tmp.begin(), tmp.end());
    vector<vector<int>> ans;
    int l = 0, r = n - 1;
    while(l < r)
        ans.push_back({tmp[l++].second, tmp[r--].second});
    return ans;
}