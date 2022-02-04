#include <vector>

using namespace std;

int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(vector<vector<char>>& board, int x, int y)
{
    board[x][y] = '#';
    for(int i=0;i<4;++i)
    {
        int nx = x+dx[i], ny=y+dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O')
            dfs(board, nx, ny);
    }
}

void solve(vector<vector<char>>& board)
{
    n = board.size(), m = board[0].size();
    for(int i = 0;i<n;++i)
    {
        if(board[i][0] == 'O')
            dfs(board, i, 0);
        if(board[i][m-1] == 'O')
            dfs(board, i, m-1);
    }
    for(int i = 0;i<m;++i)
    {
        if(board[0][i] == 'O')
            dfs(board, 0, i);
        if(board[n-1][i] == 'O')
            dfs(board, n-1, i);
    }
    for(int i =0;i<n;++i)
    {
        for(int j = 0;j<m;++j)
        {
            if(board[i][j] == '#')
                board[i][j] = 'O';
            else
                board[i][j] = 'X';
        }
    }
}
