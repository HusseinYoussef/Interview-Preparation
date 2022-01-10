#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int countLives(vector<vector<int>>& board, int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8;++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            cnt += board[nx][ny] & 1;
        }
    }
    return cnt;
}

void gameOfLife(vector<vector<int>>& board)
{
    n = board.size(), m = board[0].size();
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            int cnt = countLives(board, i, j);
            // live
            if(board[i][j] & 1)
            {
                if(cnt == 2 || cnt == 3)
                {
                    // live next, live now 11 in bits
                    board[i][j] = 3;
                }
            }
            else
            {
                if(cnt == 3)
                {
                    // live next, dead now 10 in bits
                    board[i][j] = 2;
                }
            }
        }
    }
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
            board[i][j] >>= 1;
    }
}