#include <iostream>

using namespace std;

int binaryGap(int n)
{
    int pre = -1;
    int mx = 0;
    int i =0;
    while(n)
    {
        if(n&1)
        {
            if(pre != -1)
                mx = max(mx, i-pre);
            pre = i;
        }
        n >>= 1;
        ++i;
    }
    return mx;
}
