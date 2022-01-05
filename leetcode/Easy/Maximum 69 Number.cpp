#include <iostream>

using namespace std;

int maximum69Number (int num)
{
    int tmp = num;
    int c = 0, i = 1;
    while(tmp)
    {
        int d = tmp%10;
        if(d == 6)
            c = i;
        tmp /= 10;
        i *= 10;
    }
    num += 3 * c;
    return num;
}
