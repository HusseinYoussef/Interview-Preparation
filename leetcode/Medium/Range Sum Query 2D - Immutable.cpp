#include <vector>

using namespace std;

class NumMatrix {
public:
    int n, m;
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix)
    {
        n = matrix.size(), m = matrix[0].size();
        for(int i = 0;i<n;++i)
        {
            for (int j = 0;j<m;++j)
            {
                if(i >= 1)
                    matrix[i][j] += matrix[i - 1][j];
                if(j >= 1)
                    matrix[i][j] += matrix[i][j - 1];
                if(i >= 1 && j >= 1)
                    matrix[i][j] -= matrix[i - 1][j - 1];
            }
        }
        mat = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = mat[row2][col2];
        if(row1 >= 1)
            ans -= mat[row1 - 1][col2];
        if(col1 >= 1)
            ans -= mat[row2][col1 - 1];
        if(row1 >= 1 && col1 >= 1)
            ans += mat[row1 - 1][col1 - 1];
        return ans;
    }
};