#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool ok(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<vector<char>>& board, int x, int y)
{
    if(board[x][y] == 'M')
    {
        board[x][y] = 'X';
        return;
    }
    int bombs = 0;
    for (int i = 0; i < 8;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(ok(nx, ny) && board[nx][ny] == 'M')
            ++bombs;
    }
    if(bombs)
    {
        board[x][y] = bombs + '0';
        return;
    }
    board[x][y] = 'B';
    for (int i = 0; i < 8;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(ok(nx, ny) && board[nx][ny] == 'E')
        {
            dfs(board, nx, ny);
        }
    }
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
{
    n = board.size(), m = board[0].size();
    dfs(board, click[0], click[1]);
    return board;
}