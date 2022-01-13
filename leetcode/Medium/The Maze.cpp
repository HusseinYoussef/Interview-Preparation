#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool ok(vector<vector<int>> &maze, int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && !(maze[x][y] & 1);
}

// O(N*M)
void dfs(vector<vector<int>> &maze, int x, int y, vector<int> &destination)
{
    // if vis return
    if((maze[x][y] & (1 << 1)) || ans)
        return;
    maze[x][y] |= (1 << 1);

    // currently at x, y
    if(x == destination[0] && y == destination[1])
    {
        ans = 1;
        return;
    }

    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(ok(maze, nx, ny))
        {
            while(ok(maze, nx + dx[i], ny + dy[i]))
            {
                maze[nx][ny] |= (1 << 1);
                nx = nx + dx[i], ny = ny + dy[i];
            }
            dfs(maze, nx, ny, destination);
        }
    }
}

bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    n = maze.size(), m = maze[0].size();
    dfs(maze, start[0], start[1], destination);
    return ans;
}