#include <iostream>
#include <vector>

using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops)
{
    int mnx = m;
    int mny = n;
    for (int i = 0; i < ops.size();++i)
    {
        mnx = min(mnx, ops[i][0]);
        mny = min(mny, ops[i][1]);
    }
    return mnx * mny;
}