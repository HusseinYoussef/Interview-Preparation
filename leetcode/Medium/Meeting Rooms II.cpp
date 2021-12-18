#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Interval
{
    public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

struct less_than_key
{
    inline bool operator() (const Interval& l, const Interval& r)
    {
        if(l.start != r.start)
            return (l.start < r.start);
        return (l.end < r.end);
    }
};

int minMeetingRooms(vector<Interval> &intervals)
{
    int ans=0;
    // O(N log N)
    sort(intervals.begin(), intervals.end(), less_than_key());
    priority_queue<int, vector<int>, greater<int> >pq;
    for (int i = 0; i < intervals.size();++i)
    {
        while(!pq.empty() && intervals[i].start >= pq.top())
            pq.pop();
        pq.push(intervals[i].end);
        ans = max(ans, (int)pq.size());
    }
    return ans;
}