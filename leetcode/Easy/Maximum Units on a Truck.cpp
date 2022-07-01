#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
{
    int n = boxTypes.size();

    sort(boxTypes.begin(), boxTypes.end(), cmp);

    int ans = 0;
    for (int i = 0; i < n && truckSize > 0;++i)
    {
        int boxes = min(truckSize, boxTypes[i][0]);
        ans += boxes * boxTypes[i][1];
        truckSize -= boxes;
    }

    return ans;
}