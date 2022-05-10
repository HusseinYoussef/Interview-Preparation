#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
void backtrack(int n, int row, int colMsk, int diagonal45Msk, int diagonal135Msk, int leftQueens)
{
    if(leftQueens == 0)
    {
        ++ans;
        return;
    }
    if(row >= n)
        return;

    for (int c = 0; c < n;++c)
    {
        if((colMsk & (1<<c)) == 0 && (diagonal45Msk & (1 << (row + c))) == 0 && (diagonal135Msk & (1 << (row - c + n - 1))) == 0)
        {
            backtrack(n, row + 1, colMsk | (1 << c), diagonal45Msk | (1 << (row + c)), diagonal135Msk | (1 << (row - c + n - 1)), leftQueens - 1);
        }
    }
}

int totalNQueens(int n)
{
    backtrack(n, 0, 0, 0, 0, n);
    return ans;
}