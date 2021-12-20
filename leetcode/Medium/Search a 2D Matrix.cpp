#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int rows = matrix.size(), cols = matrix[0].size();
    // (l, r)
    int l = -1, r = rows * cols, mid;
    while(r-l>1)
    {
        mid = l + (r - l) / 2;
        int i = mid / cols, j = mid % cols;
        if(matrix[i][j] == target)
            return true;
        if(matrix[i][j] > target)
            r = mid;
        else
            l = mid;
    }
    return false;
}

int main()
{
    vector<vector<int>> vec = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    searchMatrix(vec, 3);
    return 0;
}