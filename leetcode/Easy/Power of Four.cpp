#include <iostream>
#include <math.h>

using namespace std;

bool isPowerOfFour(int n)
{
    if(n <= 0)
        return false;
    double res = log10(n) / log10(4);
    return ceil(res) == floor(res);
}
int main()
{
    return 0;
}