#include <iostream>
#include <vector>

using namespace std;

bool isOneBitCharacter(vector<int>& bits)
{
    for (int i = 0; i < bits.size();)
    {
        if(i == bits.size()-1)
            return true;
        if(bits[i] == 1)
            i += 2;
        else
            ++i;
    }
    return false;
}