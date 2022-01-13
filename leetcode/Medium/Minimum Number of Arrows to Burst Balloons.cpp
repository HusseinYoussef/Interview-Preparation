#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points)
{
    sort(points.begin(), points.end());

    int pre = points[0][1], ans = 0;
    for (int i = 1; i < points.size();++i)
    {
        if(points[i][0] > pre)
        {
            pre = points[i][1];
            ++ans;
        }
        else
            pre = min(pre, points[i][1]);
    }
    return ans + 1;
}