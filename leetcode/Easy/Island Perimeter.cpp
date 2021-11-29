#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int islandPerimeter(vector<vector<int>>& grid)
{
    int ans = 0;
    int xarr[] = {1, -1, 0, 0};
    int yarr[] = {0, 0, 1, -1};

    for (int i = 0; i < grid.size();++i)
    {
        for (int j = 0; j < grid[i].size();++j)
        {
            if(grid[i][j] == 1)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + xarr[k];
                    int ny = j + yarr[k];
                    if(!(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1))
                    {
                        ++ans;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> vec = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << islandPerimeter(vec);
    return 0;
}