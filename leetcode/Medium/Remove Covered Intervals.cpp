#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    if(a[0] != b[0])
        return a[0] < b[0];
    return a[1] > b[1];
}

int removeCoveredIntervals(vector<vector<int>>& intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), cmp);
    int end = intervals[0][1];
    int removed = 0;
    for (int i = 1; i < n;++i)
    {
        if(intervals[i][1] <= end)
            ++removed;
        else
            end = intervals[i][1];
    }
    return n-removed;
}   