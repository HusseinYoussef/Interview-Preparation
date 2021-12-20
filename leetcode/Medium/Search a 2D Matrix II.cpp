#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    // O(N+M)
    int r = matrix.size(), c = matrix[0].size();
    
    // Start at Top-Right Corner and move accordingly
    int curi = 0, curj = c - 1;
    while(curi >= 0 && curi < r && curj >= 0 && curj < c)
    {
        if(matrix[curi][curj] == target)
            return true;
        if(matrix[curi][curj] > target)
            --curj;
        else if(matrix[curi][curj] < target)
            ++curi;

    }
    return false;
}