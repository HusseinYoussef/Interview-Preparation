#include <iostream>

using namespace std;

int minCostToMoveChips(vector<int>& position)
{
    int even=0, odd=0;
    for(int i =0; i<position.size() ;++i)
    {
        odd += position[i]&1;
        even += 1-position[i]&1;
    }
    return min(even, odd);
}
