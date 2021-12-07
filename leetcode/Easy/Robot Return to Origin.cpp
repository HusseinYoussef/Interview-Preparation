#include <iostream>

using namespace std;

bool judgeCircle(string moves)
{
    int vertical = 0, horizontal = 0;
    for(int i =0;i<moves.size();++i)
    {
        if(moves[i] == 'U') vertical++;
        else if(moves[i] == 'R') horizontal++;
        else if(moves[i] == 'D') vertical--;
        else horizontal--;
    }
    return vertical == 0 && horizontal == 0;
}
