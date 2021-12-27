#include <iostream>
#include <vector>

using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates)
{
    double dy = coordinates[1][1] - coordinates[0][1];
    double dx = coordinates[1][0] - coordinates[0][0];
    for(int i =2;i<coordinates.size();++i)
    {
        if((coordinates[i][1] - coordinates[1][1]) * dx - (coordinates[i][0] - coordinates[1][0]) * dy != 0)
            return false;
    }
    return true;
}
