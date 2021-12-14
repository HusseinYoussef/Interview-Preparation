#include <iostream>
#include <vector>

using namespace std;

double Area(double dX0, double dY0, double dX1, double dY1, double dX2, double dY2)
{
    double dArea = ((dX1 - dX0)*(dY2 - dY0) - (dX2 - dX0)*(dY1 - dY0))/2.0;
    return (dArea > 0.0) ? dArea : -dArea;
}
double largestTriangleArea(vector<vector<int>>& points)
{
    double mx = 0;
    int n = points.size();
    for(int i=0;i<n;++i)
        for(int j =i+1;j<n;++j)
            for(int k =j+1; k<n;++k)
                mx = max(mx, Area(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
    return mx;
}
