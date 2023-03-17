#include <vector>
#include <set>

using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums)
{
    int n = nums.size();
    // val, {arr_idx, val_idx}
    set<pair<int, pair<int, int>>> st;

    for(int i = 0;i<n;++i)
        st.insert({nums[i][0], {i, 0}});

    int mn = INT_MAX;
    int start = -1, end = -1;
    while(!st.empty())
    {
        int l = st.begin()->first;
        int r = st.rbegin()->first;
        int arrIdx = st.begin()->second.first;
        int valIdx = st.begin()->second.second;

        if(r - l < mn || (r - l == mn && l < start))
        {
            mn = r - l;
            start = l;
            end = r;
        }

        if (valIdx + 1 == nums[arrIdx].size())
            break;

        st.erase(st.begin());
        st.insert({nums[arrIdx][valIdx+1], {arrIdx, valIdx+1}});
    }

    return {start, end};
}
