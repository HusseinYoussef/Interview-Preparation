#include <vector>

using namespace std;

int trap(vector<int>& height)
{
    int n = height.size();
    vector<int> lmax(n, 0);
    lmax[0] = 0;
    for (int i = 1; i < n;++i)
    {
        lmax[i] = max(height[i - 1], lmax[i - 1]);
    }
    int rmax = 0, ans = 0;

    for (int i = n - 1; i >= 0;--i)
    {
        if(height[i] < lmax[i] && height[i] < rmax)
        {
            ans += min(lmax[i], rmax) - height[i];
        }
        rmax = max(rmax, height[i]);
    }
    return ans;
}