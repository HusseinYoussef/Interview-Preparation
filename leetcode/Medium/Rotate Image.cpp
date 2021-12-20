#include <iostream>
#include <vector>

using namespace std;

void transpose(vector<vector<int>>& matrix)
{
    // reverse the matrix around the main diagonal
    int n = matrix.size();
    for (int i = 0; i < n;++i)
    {
        for (int j = i + 1; j < n;++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
void reflect(vector<vector<int>>& matrix)
{
    // reverse it from left to right
    int n = matrix.size();
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < n/2;++j)
        {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

void rotate(vector<vector<int>>& matrix)
{
    // transpose then reflect = rotate by 90 degree clockwise
    // reflect then transpose = rotate by 90 degree counter-clockwise
    transpose(matrix);
    reflect(matrix);

    // int n = matrix.size();
    // for (int i = 0; i < n;++i)
    //     for (int j = 0; j < n;++j)
    //         matrix[i][j] += 1000;

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         int nr = j, nc = n - i - 1;
    //         int val = ((1 << 11) - 1) & matrix[i][j];
    //         matrix[nr][nc] |= (val << 11);
    //     }
    // }
    // for (int i = 0; i < n;++i)
    // {
    //     for (int j = 0; j < n;++j)
    //     {
    //         matrix[i][j] >>= 11;
    //         matrix[i][j] -= 1000;
    //     }
    // }
}