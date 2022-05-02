#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    int cnt = 0;
    int pre = 0;    
    for (int i = 1; i < n; ++i)
    {
        // overlapping
        if(intervals[i][0] < intervals[pre][1])
        {
            ++cnt;
            if(intervals[i][1] < intervals[pre][1])
                pre = i;
        }
        else
            pre = i;
    }
    return cnt;
}