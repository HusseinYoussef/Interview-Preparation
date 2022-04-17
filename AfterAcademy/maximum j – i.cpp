#include <vector>
#include <algorithm>

using namespace std;

int arrIndexDifference(vector<int>& arr)
{
/*
To solve this problem, we need to get two optimum indexes of arr[]: left index i and right index j.
For an element arr[i], we do not need to consider arr[i] for left index if there is an element smaller than arr[i] on left side of arr[i].
Similarly, if there is a greater element on right side of arr[j] then we do not need to consider this j for right index.
So we construct two auxiliary arrays LMin[] and RMax[] such that LMin[i] holds the smallest element on left side of arr[i] including arr[i],
and RMax[j] holds the greatest element on right side of arr[j] including arr[j].
After constructing these two auxiliary arrays, we traverse both of these arrays from left to right.
While traversing LMin[] and RMax[] if we see that LMin[i] is greater than RMax[j],
then we must move ahead in LMin[] (or do i++) because all elements on left of LMin[i] are greater than or equal to LMin[i].
Otherwise we must move ahead in RMax[j] to look for a greater j – i value.
*/
    // O(n) Check geeks for geeks
    int n = arr.size();
    
    vector<int> Lmin(n);
    vector<int> Rmax(n);

    Lmin[0] = arr[0];
    for (int i = 1; i < n;++i)
        Lmin[i] = min(arr[i], Lmin[i - 1]);

    Rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i)
        Rmax[i] = max(arr[i], Rmax[i + 1]);

    int i = 0, j = 0, ans = -1;
    while(i < n && j < n)
    {
        if(Lmin[i] < Rmax[j])
        {
            ans = max(ans, j - i);
            ++j;
        }
        else
            ++i;
    }
    return ans;

    // O(nlogn)
    int n = arr.size();
    vector<pair<int, int>> vec;
    for (int i = 0; i < n;++i)
        vec.push_back({arr[i], i});
    sort(vec.begin(), vec.end());

    int mx = -1;
    int ans = -1;
    for (int i = n - 1; i >= 0;--i)
    {
        if(mx > vec[i].second)
        {
            ans = max(ans, mx - vec[i].second);
        }
        mx = max(mx, vec[i].second);
    }
    return ans;
}