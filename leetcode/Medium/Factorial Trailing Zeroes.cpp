#include <iostream>

using namespace std;

int trailingZeroes(int n)
{
    // trailing zeroes result from tens 10's
    // so look for how many 10 the factorial has
    // 10 = 5*2, so look for how many 5's ans 2's

    // since number of 5's always <= number of 2's

    // O(n log n)
    int fives=0;
    for(int i = 1;i<=n;++i)
    {
        int tmp = i;
        while(tmp % 5 == 0)
        {
            ++fives;
            tmp /= 5;
        }
    }
    return fives;

    // Log(n)
    // Multiple of 5 provides one 5, multiple of 25 provides two 5 and so on.
    int fives = 0;
    for(int i = 5; i<=n; i*=5)
        fives += n / i;
    return fives;
}
