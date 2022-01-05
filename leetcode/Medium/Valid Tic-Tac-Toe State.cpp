#include <iostream>
#include <vector>

using namespace std;

bool checkWin(vector<string>& board, char p)
{
    for (int i = 0; i < 3;++i)
    {
        if(board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return true;
        if(board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return true;
    }
    if(board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return true;
    if(board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return true;
    return false;
}

bool validTicTacToe(vector<string>& board)
{
    int xs = 0, os = 0;
    for (int i = 0; i < 3;++i)
    {
        for (int j = 0; j < 3;++j)
        {
            xs += board[i][j] == 'X';
            os += board[i][j] == 'O';
        }
    }
    if(xs - os == 0)
        return !checkWin(board, 'X');
    if(xs - os == 1)
        return !checkWin(board, 'O');
    return false;
}