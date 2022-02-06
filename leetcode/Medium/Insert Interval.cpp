#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    for(int i =0;i<n;++i)
    {
        if(newInterval[0] == -1)
        {
            ans.push_back(intervals[i]);
            continue;
        }
        if(intervals[i][1] < newInterval[0])
            ans.push_back(intervals[i]);
        else if(intervals[i][0] > newInterval[1])
        {
            ans.push_back(newInterval);
            ans.push_back(intervals[i]);
            newInterval[0] = -1;
        }
        else
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }
    if(newInterval[0] != -1)
        ans.push_back(newInterval);
    return ans;
}
