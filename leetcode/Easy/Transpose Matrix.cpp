#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix)
{
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> t(c, vector<int>(r));

    for (int i = 0; i < r;++i)
    {
        for (int j = 0; j < c;++j)
        {
            t[j][i] = matrix[i][j];
        }
    }
    return t;
}