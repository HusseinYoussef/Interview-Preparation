#include <iostream>
#include <math.h>

using namespace std;

int reverse(int x)
{
    int arr[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
    if(x < 0)
        arr[9] = 8;
    int tmp = 0;
    int i = 0;
    bool sign = x < 0;
    bool f = (log10(abs(x)-1) + 1) >= 10;
    while(x)
    {
        int d = x % 10;
        if(f)
        {
            if(abs(d) < arr[i])
                f = 0;
            else if(abs(d) > arr[i])
                return 0;
        }
        tmp = tmp * 10 + d;
        x /= 10;
        ++i;
    }
    return tmp;
}