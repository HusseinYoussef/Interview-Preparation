#include <iostream>
#include <vector>

using namespace std;

int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
{
    // O(N + 6)
    int n = tops.size();
    vector<int> t(7, 0);
    vector<int> b(7, 0);
    vector<int> d(7, 0);
    for(int i = 0;i<n;++i)
    {
        if(tops[i] == bottoms[i])
            ++d[tops[i]];
        else
        {
            ++t[tops[i]];
            ++b[bottoms[i]];
        }
    }
    int ans = 1e7;
    for(int i = 1;i<=6;++i)
    {
        int lft = n-d[i];
        if(t[i] + b[i] == lft)
        {
            ans = min(ans, min(lft-t[i], lft-b[i]));
        }
    }
    if(ans == 1e7)
        return -1;
    return ans;

    // O(6*N)
    int n = tops.size();
    int ans = 1e7;
    for(int i = 1;i<=6;++i)
    {
        int t = 0, b = 0, f = 1;
        for(int j = 0;j<n;++j)
        {
            if(tops[j] != i && bottoms[j] != i)
            {
                f = 0;
                break;
            }
            if(tops[j] != i && bottoms[j] == i)
                ++t;
            if(bottoms[j] != i && tops[j] == i)
                ++b;
        }
        if(f)
            ans = min(ans, min(t, b));
    }
    if(ans == 1e7)
        return -1;
    return ans;
}
