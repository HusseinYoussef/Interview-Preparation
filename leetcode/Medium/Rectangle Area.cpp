#include <iostream>

using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

    // subtract the overlapping
    int width = min(ax2, bx2) - max(ax1, bx1), height = min(ay2, by2) - max(ay1, by1);
    
    // Overlap
    if(width > 0 && height > 0)
        return area - width * height;
    return area;
}