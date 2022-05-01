#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumPassesOfMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(matrix[i][j] > 0)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int cst = dist[x][y];
        q.pop();

        for (int i = 0; i < 4;++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1 && matrix[nx][ny] < 0)
            {
                matrix[nx][ny] = abs(matrix[nx][ny]);
                dist[nx][ny] = cst + 1;
                q.push({nx, ny});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(matrix[i][j] < 0)
                return -1;
            ans = max(ans, dist[i][j]);
        }
    }
    return ans;
}