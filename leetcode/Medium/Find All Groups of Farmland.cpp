#include <iostream>
#include <vector>

using namespace std;

int n,m,mxr,mxc;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(vector<vector<int>>& land, int x, int y)
{
    land[x][y] = 0;
    mxr = max(mxr, x);
    mxc = max(mxc, y);
    for(int i = 0;i<4;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && land[nx][ny] == 1)
            dfs(land, nx, ny);
    }
}
vector<vector<int>> findFarmland(vector<vector<int>>& land)
{
    n = land.size(), m = land[0].size();
    vector<vector<int>>ans;
    for(int i =0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(land[i][j] == 1)
            {
                mxr = i, mxc = j;
                dfs(land, i, j);
                ans.push_back({i, j, mxr, mxc});
            }
        }
    }
    return ans;
}
