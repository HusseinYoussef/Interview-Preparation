#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int findLongestChain(vector<vector<int>>& pairs)
{
    int n = pairs.size();
    //smaller tail has a better opportunity to append more future pairs
    sort(pairs.begin(), pairs.end(), cmp);

    int ans = 0, cur = INT_MIN;
    for (int i = 0; i < n;++i)
    {
        if(pairs[i][0] > cur)
        {
            cur = pairs[i][1];
            ++ans;
        }
    }
    return ans;
}