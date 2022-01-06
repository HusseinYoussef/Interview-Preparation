#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool vis[7][7], ans = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void dfs(vector<vector<char>>& board, string &word, int idx, int x, int y)
{
    if(idx == word.size() || ans)
    {
        ans = 1;
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4;++i)
    {
        if(ans)
            break;
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && board[nx][ny] == word[idx])
        {
            dfs(board, word, idx + 1, nx, ny);
        }
    }
    vis[x][y] = 0;
}

bool exist(vector<vector<char>>& board, string word)
{
    n = board.size(), m = board[0].size();
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(board[i][j] == word[0])
                dfs(board, word, 1, i, j);
            if(ans)
                return true;
        }
    }
    return false;
}