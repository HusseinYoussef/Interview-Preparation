#include <vector>

using namespace std;

bool f = 0;
void rec(vector<vector<char>>& board, vector<int> &rs, vector<int> &cs, vector<vector<int>> &boxes, vector<pair<int, int>> &dots, int idx)
{
    if(idx == dots.size() || f)
    {
        f = 1;
        return;
    }

    int r = dots[idx].first, c = dots[idx].second;
    for (int i = 1; i <= 9;++i)
    {
        int j = 1 << i;
        // used in row or col or box
        if((rs[r] & j) || (cs[c] & j) || (boxes[r/3][c/3] & j))
            continue;

        rs[r] |= j;
        cs[c] |= j;
        boxes[r / 3][c / 3] |= j;
        board[r][c] = i + '0';
        rec(board, rs, cs, boxes, dots, idx + 1);
        if(f)
            break;
        // revert changes
        rs[r] ^= j;
        cs[c] ^= j;
        boxes[r / 3][c / 3] ^= j;
        board[r][c] = '.';
    }
}

void solveSudoku(vector<vector<char>>& board)
{
    vector<int> rs(9, 0); // each cell i contains a mask of the used numbers in row i
    vector<int> cs(9, 0); // each cell j contains a mask of the used numbers in col j
    vector<vector<int>> boxes(3, vector<int>(3, 0)); // each cell i, j contains a mask of the used numbers in box i, j

    vector<pair<int, int>> dots;
    for (int i = 0; i < 9;++i)
    {
        for (int j = 0; j < 9;++j)
        {
            if(board[i][j] == '.')
                dots.push_back({i, j});
            else
            {
                rs[i] |= 1 << (board[i][j] - '0');
                cs[j] |= 1 << (board[i][j] - '0');
                boxes[i / 3][j / 3] |= 1 << (board[i][j] - '0');
            }
        }
    }
    rec(board, rs, cs, boxes, dots, 0);
}