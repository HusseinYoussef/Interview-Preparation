#include <iostream>

using namespace std;

int getSum(int a, int b)
{
    bool carry = 0;
    int ans = 0, i;
    for (i = 0;i<32;++i)
    {
        int idx = 1 << i;
        if(carry ^ ((a & idx) != 0) ^ ((b & idx) != 0))
            ans |= idx;
        carry = (carry && ((a & idx) || (b & idx))) || ((a & idx) && (b & idx));
    }
    
    if(carry && i < 32)
        ans |= 1 << i;

    return ans;
}
