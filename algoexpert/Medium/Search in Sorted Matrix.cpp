#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();

    int x = 0, y = m - 1;
    while(x < n && y >= 0)
    {
        if(matrix[x][y] == target)
            return {x, y};
        
        if(matrix[x][y] < target)
            ++x;
        else
            --y;
    }

    return {-1, -1};
}