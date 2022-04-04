
/*
    Problem Statement


    You're given a two-dimensional array (a matrix) of potentially unequal height
    and width containing only 0's (land) and 1's forming a river determine its size.
*/

#include <vector>
#include <cstring>
using namespace std;

int n, m, cnt;
bool vis[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(vector<vector<int>> &matrix, int x, int y)
{
    vis[x][y] = 1;
    ++cnt;
    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] == 1 && vis[nx][ny] == 0)
            dfs(matrix, nx, ny);
    }
}

vector<int> riverSizes(vector<vector<int>> matrix)
{
    n = matrix.size(), m = matrix[0].size();
    vector<int> ans;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(matrix[i][j] == 1 && vis[i][j] == 0)
            {
                cnt = 0;
                dfs(matrix, i, j);
                ans.push_back(cnt);
            }
        }
    }
    return ans;
}
