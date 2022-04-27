#include <vector>
#include <unordered_map>

using namespace std;

int maxPoints(vector<vector<int>>& points)
{
    int n = points.size();

    int ans = 0;
    for (int i = 0; i < n;++i)
    {
        int mx = 0, overlap = 0, vertical = 0;
        unordered_map<double, int> mp;
        for (int j = i + 1; j < n;++j)
        {
            // point j overlaps on point i
            if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                ++overlap;
            // point j is vertical to point i (same line parallel to Y-axis)
            else if(points[i][0] == points[j][0])
                ++vertical;
            else
            {
                double slope = (points[i][1] - points[j][1]) * 1.0 / (points[i][0] - points[j][0]);
                ++mp[slope];
                mx = max(mx, mp[slope]);
            }
        }
        ans = max(ans, max(vertical, mx + overlap) + 1);
    }
    return ans;
}