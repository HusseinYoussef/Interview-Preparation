#include <iostream>

using namespace std;

double pow(double x, int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    int exp = abs(n / 2);
    double ans = pow(x, exp);
    if(n & 1)
        return x * ans * ans;
    return ans * ans;
}

double myPow(double x, int n)
{
    if(x == 1)
        return 1;
    if(n < 0)
        x = 1 / x;
    return pow(x, n);
}