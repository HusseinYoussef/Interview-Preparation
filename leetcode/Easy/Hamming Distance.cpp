#include <iostream>

using namespace std;

int hammingDistance(int x, int y)
{
    int ans =0;
    for(int i =0;i<32;++i)
    {
        int bit = 1 << i;
        if((bit & x) > 0 != (bit & y) > 0)
            ans++;
    }
    return ans;
}
