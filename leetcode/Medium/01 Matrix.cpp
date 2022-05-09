#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
{
    int n = mat.size(), m = mat[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(mat[i][j] == 0)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int cst = dist[x][y];
        q.pop();
        for (int i = 0; i < 4;++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1)
            {
                dist[nx][ny] = cst + 1;
                q.push({nx, ny});
            }
        }
    }
    return dist;
}