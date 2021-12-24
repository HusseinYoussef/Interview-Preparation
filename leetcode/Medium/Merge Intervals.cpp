#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    int start = -1, end = -1;
    vector<vector<int>> ans;
    for (int i = 0; i < n;++i)
    {
        if(start == -1 && end == -1)
        {
            start = intervals[i][0], end = intervals[i][1];
        }
        else if(intervals[i][0] <= end)
        {
            end = max(end, intervals[i][1]);
        }
        else
        {
            ans.push_back({start, end});
            start = intervals[i][0], end = intervals[i][1];
        }
    }
    ans.push_back({start, end});
    return ans;
}