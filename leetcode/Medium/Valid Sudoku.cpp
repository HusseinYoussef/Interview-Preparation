#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
    int rows[9], cols[9];
    for (int i = 0; i < 9;++i)
        rows[i] = cols[i] = 0;
    // check cols and rows
    for (int i = 0; i < 9;++i)
    {
        for (int j = 0; j < 9;++j)
        {
            if(board[i][j] != '.')
            {
                int r = 0, c = 0;
                if(!rows[i])
                {
                    for (int k = 0; k < 9;++k)
                    {
                        if(board[i][k] != '.')
                        {
                            int d = board[i][k] - '0';
                            if((1 << d) & r)
                                return false;
                            r |= 1 << d;
                        }
                    }
                    rows[i] = 1;
                }
                if(!cols[j])
                {
                    for (int k = 0; k < 9;++k)
                    {
                        if(board[k][j] != '.')
                        {
                            int d = board[k][j] - '0';
                            if((1 << d) & c)
                                return false;
                            c |= 1 << d;
                        }
                    }
                    cols[j] = 1;
                }
            }
        }
    }
    int b1, b2, b3;
    for (int b = 0; b < 9;b+=3)
    {
        b1 = b2 = b3 = 0;
        for (int i = b; i < b + 3;++i)
        {
            for (int j = 0; j < 9;++j)
            {
                if(board[i][j] != '.')
                {
                    int d = board[i][j] - '0';
                    int &block = (j < 3)? b1 : (j < 6) ? b2 : b3;
                    if((1 << d) & block)
                        return false;
                    block |= 1 << d;
                }
            }
        }
    }
    return true;
}