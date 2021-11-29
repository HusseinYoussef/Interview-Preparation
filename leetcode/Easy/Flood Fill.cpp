#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int xarr[] = {1, -1, 0, 0};
int yarr[] = {0, 0, 1, -1};

bool ok(vector<vector<int>>& image, int x, int y, int old)
{
    return x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == old;
}

void dfs(vector<vector<int>>& image, int x, int y, int old, int color)
{
    image[x][y] = color;
    for (int i = 0; i < 4;++i)
    {
        int nx = x + xarr[i];
        int ny = y + yarr[i];
        if(ok(image, nx,ny, old))
        {
            dfs(image, nx, ny, old, color);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    if(image[sr][sc] == newColor)
        return image;
    dfs(image, sr, sc, image[sr][sc], newColor);
    return image;
}