#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    int li = 0, lj = 0;
    int ri = matrix.size(), rj = matrix[0].size();

    int dir = 0;
    vector<int> ans;
    while(ri-li && rj-lj)
    {
        if(dir%4 == 0)
        {
            for (int i = li, j = lj; j < rj;++j)
                ans.push_back(matrix[i][j]);
            ++li;
        }
        else if(dir%4 == 1)
        {
            for (int i = li, j = rj-1; i < ri;++i)
                ans.push_back(matrix[i][j]);
            --rj;
        }
        else if(dir%4 == 2)
        {
            for (int i = ri-1, j = rj-1; j >= lj;--j)
                ans.push_back(matrix[i][j]);
            --ri;
        }
        else
        {
            for (int i = ri - 1, j = lj; i >= li;--i)
                ans.push_back(matrix[i][j]);
            ++lj;
        }
        ++dir;
    }
    return ans;
}