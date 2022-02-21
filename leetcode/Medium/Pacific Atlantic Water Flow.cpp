#include <vector>
#include <cstring>

using namespace std;

int n, m;
int vis[205][205];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void dfs(vector<vector<int>>& heights, int x, int y, bool ocean)
{
    vis[x][y] |= 1 << ocean;

    for (int i = 0; i < 4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && heights[nx][ny] >= heights[x][y] && !(vis[nx][ny] & (1<<ocean)))
            dfs(heights, nx, ny, ocean);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
    n = heights.size(), m = heights[0].size();
    memset(vis, 0, sizeof(vis));

    // Pacific
    bool ocean = 0;
    for (int i = 0; i < m;++i)
    {
        if(!(vis[0][i] & (1<<ocean)))
            dfs(heights, 0, i, ocean);
    }
    for (int i = 0; i < n;++i)
    {
        if(!(vis[i][0] & (1<<ocean)))
            dfs(heights, i, 0, ocean);
    }
    // Atlantic
    ocean = 1;
    for (int i = 0; i < m;++i)
    {
        if(!(vis[n-1][i] & (1<<ocean)))
            dfs(heights, n-1, i, ocean);
    }
    for (int i = 0; i < n;++i)
    {
        if(!(vis[i][m-1] & (1<<ocean)))
            dfs(heights, i, m-1, ocean);
    }
    // Find nodes visited by both oceans
    vector<vector<int>> ans;
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
            if(vis[i][j] == 3)
                ans.push_back({i, j});
    }
    return ans;
}