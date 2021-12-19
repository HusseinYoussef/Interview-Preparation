#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    bool setR = 0, setC = 0;
    // special case for first row and column
    for (int i = 0; i < matrix.size();++i)
    {
        if(matrix[i][0] == 0)
            setC = 1;
    }
    for (int i = 0; i < matrix[0].size();++i)
    {
        if(matrix[0][i] == 0)
            setR = 1;
    }
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            // set the first cell of row and column as a flag
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < matrix.size();++i)
    {
        for (int j = 1; j < matrix[0].size();++j)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    // handle first row and column separately
    if(setR)
    {
        for (int j = 0; j < matrix[0].size();++j)
            matrix[0][j] = 0;
    }
    if(setC)
    {
        for (int i = 0; i < matrix.size();++i)
            matrix[i][0] = 0;
    }
}