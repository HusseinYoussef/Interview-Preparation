#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
{
    vector<vector<int>> ans(r, vector<int>(c));
    if(r*c != mat.size()*mat[0].size())
        return mat;
    int x=0,y=0;
    for(int i =0;i<mat.size();++i)
    {
        for(int j =0;j<mat[0].size();++j,++y)
        {
            if(y >= c)
            {
                x++;
                y = 0;
            }
            ans[x][y] = mat[i][j];
        }
    }
    return ans;  
}
