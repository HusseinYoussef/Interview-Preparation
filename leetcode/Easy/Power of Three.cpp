#include <iostream>
#include <math.h>

using namespace std;

bool isPowerOfThree(int n)
{
    if(n <= 0)
        return false;
    double res = log10(n) / log10(3);
    return ceil(res) == floor(res);
}
int main()
{
    return 0;
}