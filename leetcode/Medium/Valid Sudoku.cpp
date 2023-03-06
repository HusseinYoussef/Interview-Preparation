#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
    int rows[9];
    int cols[9];
    int boxes[3][3];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    memset(boxes, 0, sizeof(boxes));

    for(int i = 0;i<9;++i)
    {
        for(int j = 0;j<9;++j)
        {
            if(board[i][j] != '.')
            {
                int idx = 1 << (board[i][j] - '0');
                if((rows[i] & idx) || 
                    (cols[j] & idx) || 
                    (boxes[i/3][j/3] & idx))
                    return false;

                rows[i] |= idx;
                cols[j] |= idx;
                boxes[i/3][j/3] |= idx;
            }
        }
    }
    return true;
}
