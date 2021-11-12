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
}

int main()
{
    cout << reverseBits(00000010100101000001111010011100);
    return 0;
}