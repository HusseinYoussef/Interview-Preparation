#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int rowMedian(vector<vector<int>>& arr)
{
    int n = arr.size(), m = arr[0].size();

    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n;++i)
    {
        mn = min(mn, arr[i][0]);
        mx = max(mx, arr[i][m - 1]);
    }

    int total = n * m;
    int half = total / 2;
    // median should have half elements before it inclusive
    // Search Range (l,r)
    // T T T T T F F F F, we want first false
    int l = mn - 1, r = mx + 1, mid;
    while(r-l > 1)
    {
        mid = l + (r - l) / 2;

        // count how many elements <= mid
        int cnt = 0;
        for (int i = 0; i < n;++i)
        {
            cnt += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
        }

        if(cnt <= half)
            l = mid;
        else
            r = mid;
    }
    return r;
}