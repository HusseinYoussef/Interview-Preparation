#include <vector>
#include <algorithm>

using namespace std;

bool static cmp(vector<int> &a, vector<int> &b)
{
    int val1 = abs(a[0]-a[1]), val2 = abs(b[0]-b[1]);
    return val1 > val2;
}

int twoCitySchedCost(vector<vector<int>>& costs)
{
    int n = costs.size();
    // sort using the abs difference (descendingly) ~ how much we can save
    // then for big differences, try to save money as much as possible
    sort(costs.begin(), costs.end(), cmp);

    int ans = 0;
    int a = 0, b = 0;
    for(int i = 0;i<n;++i)
    {
        // choose a or b
        if(a*2 >= n || (b*2 < n && costs[i][1] < costs[i][0]))
        {
            ++b;
            ans += costs[i][1];
        }
        else
        {
            ++a;
            ans += costs[i][0];
        }
    }
    return ans;
}
