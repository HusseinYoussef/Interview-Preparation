#include <iostream>
#include <string>
#include <cstring>
#include <exception>

using namespace std;

struct GameEndException : public exception {
   const char * what () const throw () {
      return "Game end";
   }
};

struct AlreadyTakenException : public exception {
   const char * what () const throw () {
      return "taken place";
   }
};

class TicTacToe {
public:
    /** Initialize your data structure here. */
    int grid[3][3];
    // 0 = x  , 1 = O
    bool turn, end;
    TicTacToe()
    {
        initialize();
    }

	void initialize()
	{
        turn = end = 0;
        memset(grid, -1, sizeof(grid));
	}

    bool allTaken()
    {
        int cnt = 0;
        for (int i = 0; i < 3;++i)
        {
            for (int j = 0; j < 3;++j)
                cnt += (grid[i][j] == -1);
        }
        return cnt == 0;
    }
    bool isWin()
    {
        // rows
        for (int i = 0; i < 3;++i)
        {
            if(grid[i][0] != -1 && grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
                return true;
        }
        // cols
        for (int i = 0; i < 3;++i)
        {
            if(grid[0][i] != -1 && grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
                return true;
        }
        if (grid[0][0] != -1 && grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2])
            return true;
        else if (grid[0][2] != -1 && grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0])
            return true;
        return false;
    }
    bool move(int row, int col)
    {
        if(allTaken())
        {
            end = 1;
        }
        if(end)
        {
            throw GameEndException();
        }
        if(grid[row][col] != -1)
        {
            throw AlreadyTakenException();
        }
        grid[row][col] = turn;
        bool win = isWin();
        if(win)
        {
            end = 1;
            return win;
        }
        turn = !turn;
        return win;
    }
};