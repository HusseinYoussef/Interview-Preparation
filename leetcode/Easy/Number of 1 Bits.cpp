#include <iostream>

using namespace std;

int hammingWeight(uint32_t n)
{
    int ans = 0;
    while(n)
    {
        ans += n & 1;
        n >>= 1;
    }
    return ans;
}

int main()
{
    cout << hammingWeight(3);
    return 0;
}