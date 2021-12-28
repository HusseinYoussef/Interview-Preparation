#include <iostream>

using namespace std;

int numberOfSteps(int num)
{
    int ans =0;
    while(num)
    {
        if(num & 1)
            ans+=2;
        else
            ans++;
        num >>= 1;
    }
    return max(ans-1, 0);
}
