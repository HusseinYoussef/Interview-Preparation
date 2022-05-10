#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<string>> &ans, int n, vector<string> &grid, int row, int colMsk, int diagonal45Msk, int diagonal135Msk, int leftQueens)
{
    if(leftQueens == 0)
    {
        ans.push_back(grid);
        return;
    }
    if(row >= n)
        return;

    for (int c = 0; c < n;++c)
    {
        if(grid[row][c] == '.' && (colMsk & (1<<c)) == 0 && (diagonal45Msk & (1 << (row + c))) == 0 && (diagonal135Msk & (1 << (row - c + n - 1))) == 0)
        {
            grid[row][c] = 'Q';
            backtrack(ans, n, grid, row + 1, colMsk | (1 << c), diagonal45Msk | (1 << (row + c)), diagonal135Msk | (1 << (row - c + n - 1)), leftQueens - 1);
            grid[row][c] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> grid(n, string(n, '.'));

    vector<vector<string>> ans;
    backtrack(ans, n, grid, 0, 0, 0, 0, n);
    return ans;
}