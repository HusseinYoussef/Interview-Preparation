#include <iostream>
#include <math.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if(n <= 0)
        return false;
    int ans = log2(n);
    return n == pow(2, ans);
}

int main()
{
    return 0;
}