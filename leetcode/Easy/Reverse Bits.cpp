#include <iostream>
#include <bitset>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    
    bitset<32> set(n);
    uint32_t ans = set[31];
    uint32_t c = 1;
    for (int i = 30; i >= 0; --i)
    {
        c *= 2;
        ans += c * set[i];
    }
    return ans;

    // uint32_t ans = (n & (1 << 31)) > 0;
    // uint32_t c = 1;
    // for (int i = 1; i < 32;++i)
    // {
    //     c *= 2;
    //     ans += c * ((n & (1 << (31 - i))) > 0);
    // }
    // return ans;
}

int main()
{
    cout << reverseBits(10000000000000000000000000000000);
    return 0;
}