#include <iostream>

using namespace std;

int arrangeCoins(int n)
{
    int l = 1, r = n;
    long long mid;
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(mid*(1+mid)/2 > n)
            r = mid-1;
        else
            l = mid+1;
    }
    return r;
}

int main()
{
    cout << arrangeCoins(8);
    return 0;
}