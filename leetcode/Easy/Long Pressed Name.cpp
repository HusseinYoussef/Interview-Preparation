#include <iostream>

using namespace std;

bool isLongPressedName(string name, string typed)
{
    int i , j;
    for (i = 0, j = 0; i < name.size() || j < typed.size();++j)
    {
        if(i < name.size() && name[i] == typed[j])
            ++i;
        else if(i == 0 || typed[j] != name[i-1]) // check if it is a repeated character of the last character
            return false;
    }
    return (i == name.size()) && (j == typed.size());
}