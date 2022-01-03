
#include <iostream>
#include <vector>

using namespace std;

vector<int> luckyNumbers (vector<vector<int>>& matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int>vec, ans;
    for(int j = 0;j<m;++j)
    {
        int mx = 0;
        for(int i = 0;i<n;++i)
        {
            mx = max(mx, matrix[i][j]);
        }
        vec.push_back(mx);
    }

    for(int i = 0;i<n;++i)
    {
        int mn = INT_MAX, idx;
        for(int j = 0;j<m;++j)
        {
            if(matrix[i][j] < mn)
            {
                mn = matrix[i][j];
                idx = j;
            }
        }
        if(mn == vec[idx])
            ans.push_back(mn);
    }
    return ans;
}
