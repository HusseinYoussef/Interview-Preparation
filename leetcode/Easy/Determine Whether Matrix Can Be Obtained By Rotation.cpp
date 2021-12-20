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

bool check(vector<vector<int>>& mat, vector<vector<int>>& target)
{
    int n = mat.size();
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < n;++j)
        {
            if(mat[i][j] != target[i][j])
                return false;
        }
    }
    return true;
}

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
{
    // transpose then reflect = rotate by 90 degree clockwise
    if(check(mat, target))
        return true;
    
    transpose(mat);
    reflect(mat);

    if(check(mat, target))
        return true;
    
    transpose(mat);
    reflect(mat);

    if(check(mat, target))
        return true;
    
    transpose(mat);
    reflect(mat);

    if(check(mat, target))
        return true;

    return false;
}