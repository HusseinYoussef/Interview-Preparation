
/*
    Problem Statement

    Write a function that returns a modified version of the input matrix, where
    all of the islands (not touching border) are removed. You remove an island by replacing it with  
*/

#include <vector>
using namespace std;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(vector<vector<int>> &matrix, int x, int y)
{
    matrix[x][y] = 3;
    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] == 1)
        {
            dfs(matrix, nx, ny);
        }
    }
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix)
{
    n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < m;++i)
    {
        if(matrix[0][i] == 1)
            dfs(matrix, 0, i);
        if(matrix[n-1][i] == 1)
            dfs(matrix, n - 1, i);
    }
    for (int i = 0; i < n;++i)
    {
        if(matrix[i][0] == 1)
            dfs(matrix, i, 0);
        if(matrix[i][m-1] == 1)
            dfs(matrix, i, m-1);
    }
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(matrix[i][j] == 3)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    return matrix;
}