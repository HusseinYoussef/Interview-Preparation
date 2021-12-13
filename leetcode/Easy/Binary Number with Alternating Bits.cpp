#include <iostream>

using namespace std;

bool hasAlternatingBits(int n)
{
    bool last = n&1;
    while(n)
    {
        n >>= 1;
        if(last == (n&1))
            return false;
        last = n&1;
    }
    return true;
}
