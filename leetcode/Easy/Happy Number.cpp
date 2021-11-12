#include <iostream>

using namespace std;

int getnext(int n)
{
    int num = 0;
    while (n)
    {
        int d = n % 10;
        num += d * d;
        n /= 10;
    }
    return num;
}

bool isHappy(int n)
{
    int tor = n, hare = n;
    while (true)
    {
        tor = getnext(tor);
        hare = getnext(getnext(hare));
        if(tor == 1 || hare == 1)
            return true;
        else if(tor == hare)
            return false;
    }
    return false;
}

int main()
{
    isHappy(7);
    return 0;
}