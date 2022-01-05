#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height)
{
    int n = height.size();
    int l = 0, r = n-1;
    int ans = 0;
    while(l<r)
    {
        ans = max(ans, (r - l) * min(height[l], height[r]));
        int lval = height[l], rval = height[r];
        if(lval < rval)
            while(l<r && height[l] <= lval)
                ++l;
        else
            while(r>l && height[r] <= rval)
                --r;
    }
    return ans;
}
