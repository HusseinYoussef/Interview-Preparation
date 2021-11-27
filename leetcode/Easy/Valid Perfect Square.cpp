#include <iostream>

using namespace std;

bool isPerfectSquare(int num)
{
    // for (long long i = 1; i * i <= num;++i)
    // {
    //     if(i*i == num)
    //         return true;
    // }
    // return false;

    // O(log n)
    long long l = 1, r = num, mid;
    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(mid * mid == num)
            return true;
        if(mid * mid < num)
            l = mid + 1;
        else
            r = mid;
    }
    return l*l == num;
}

int main()
{
    isPerfectSquare(15);
    return 0;
}