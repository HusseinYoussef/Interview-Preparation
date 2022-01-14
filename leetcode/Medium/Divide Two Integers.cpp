#include <iostream>
#include <climits>

using namespace std;

int divide(int dividend, int divisor)
{
    // dividend = quotient * divisor + reminder
    // 21 = 7 * 3   , every number can be represented as sum of powers of 2
    // 21 = 1*3 + 2*3 + 4*3
    // so find each power of 2 then subtract then solve the same problem
    // find 4, then 21 - 4*3 => 9 = 1*3 + 2*3 ,and so on
    if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    bool sign = (dividend < 0) ^ (divisor < 0);
    long long div = abs(divisor), dvd = abs(dividend), ans = 0;
    while(dvd >= div)
    {
        // how many shift
        int cnt = 0;
        long long tmp = div;
        while(dvd - (tmp << 1) >= 0)
        {
            ++cnt;
            tmp <<= 1;
        }
        ans += (1 << cnt);
        dvd -= tmp;
    }
    if(sign)
        return -1 * ans;
    return ans;
}