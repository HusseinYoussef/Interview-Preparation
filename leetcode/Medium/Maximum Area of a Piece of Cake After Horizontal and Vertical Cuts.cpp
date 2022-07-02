#include <vector>
#include <algorithm>

using namespace std;

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
{
    int mod = 1e9+7;

    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    horizontalCuts.push_back(h);
    verticalCuts.push_back(w);

    int mxh = horizontalCuts[0];
    int mxw = verticalCuts[0];

    for(int i = 0;i<horizontalCuts.size()-1;++i)
    {
        mxh = max(mxh, horizontalCuts[i+1] - horizontalCuts[i]);
    }

    for(int i = 0;i<verticalCuts.size()-1;++i)
    {
        mxw = max(mxw, verticalCuts[i+1] - verticalCuts[i]);
    }

    return (int)(((long)mxw * (long)mxh) % mod);
}
