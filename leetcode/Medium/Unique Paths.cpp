#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    int arr[m][n];
    arr[m - 1][n - 1] = 1;
    // Bottom -Up DP
    for (int i = m - 1; i >= 0;--i)
    {
        for (int j = n - 1; j >= 0;--j)
        {
            if (i == m-1 && j == n-1)
                continue;
            int d = 0, r = 0;
            if(i+1 < m)
                d = arr[i + 1][j];
            if (j + 1 < n)
                r = arr[i][j + 1];
            arr[i][j] = d + r;
        }
    }
    return arr[0][0];
}