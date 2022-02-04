#include <vector>

using namespace std;

int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(vector<vector<bool>> &vis, vector<vector<char>>& board, int x, int y)
{
    vis[x][y] = 1;
    for(int i=0;i<4;++i)
    {
        int nx = x+dx[i], ny=y+dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && board[nx][ny] == 'O')
            dfs(vis, board, nx, ny);
    }
}

void solve(vector<vector<char>>& board)
{
    n = board.size(), m = board[0].size();
    vector<vector<bool>> vis(n+1, vector<bool> (m+1));
    for(int i = 0;i<n;++i)
    {
        if(board[i][0] == 'O' && !vis[i][0])
            dfs(vis, board, i, 0);
        if(board[i][m-1] == 'O' && !vis[i][m-1])
            dfs(vis, board, i, m-1);
    }
    for(int i = 0;i<m;++i)
    {
        if(board[0][i] == 'O' && !vis[0][i])
            dfs(vis, board, 0, i);
        if(board[n-1][i] == 'O' && !vis[n-1][i])
            dfs(vis, board, n-1, i);
    }
    for(int i =0;i<n;++i)
    {
        for(int j = 0;j<m;++j)
            if(!vis[i][j] && board[i][j] == 'O')
                board[i][j] = 'X';
    }
}
