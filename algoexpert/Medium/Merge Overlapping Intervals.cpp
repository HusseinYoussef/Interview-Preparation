
/*
    Problem Statement


    Write a function that takes in a non-empty array of arbitrary intervals,
    merges any overlapping intervals, and returns the new intervals in no
    particular order.
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    int l = intervals[0][0], r = intervals[0][1];
    for (int i = 1; i < n;++i)
    {
        if(intervals[i][0] <= r)
            r = max(r, intervals[i][1]);
        else
        {
            ans.push_back({l, r});
            l = intervals[i][0], r = intervals[i][1];
        }
    }
    ans.push_back({l, r});
    return ans;
}
