#include <iostream>
#include <vector>

using namespace std;

bool isRobotBounded(string instructions)
{
    int x = 0, y = 0, i = 0;
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int j = 0; j < instructions.size();++j)
    {
        if(instructions[j] == 'R')
            i = (i + 1) % 4;
        else if(instructions[j] == 'L')
            i = (i + 3) % 4;
        else
            x += d[i].first, y += d[i].second;
    }
    return (x == 0 && y == 0) || i != 0;
}