#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int minAreaRect(vector<vector<int>>& points)
{
    int n = points.size();
    map<pair<int, int>, bool> ps;
    for (int i = 0; i < n;++i)
    {
        int x = points[i][0];
        int y = points[i][1];
        ps[{x, y}] = 1;
    }

    int ans = INT_MAX;
    // p1 (x1, y1) bottom_left corner
    // p2 (x2, y2) top_right corner  which has bigger x & y
    for(auto &p1 : ps)
    {
        for(auto &p2 : ps)
        {
            if(p2.first.first > p1.first.first && p2.first.second > p1.first.second)
            {
                // check for (x1, y2) and (x2, y1)
                if(ps.find({p1.first.first, p2.first.second}) != ps.end() && ps.find({p2.first.first, p1.first.second}) != ps.end())
                {
                    ans = min(ans, abs(p1.first.first - p2.first.first) * abs(p1.first.second - p2.first.second));
                }
            }
        }
    }
    if(ans == INT_MAX)
        return 0;
    return ans;
}