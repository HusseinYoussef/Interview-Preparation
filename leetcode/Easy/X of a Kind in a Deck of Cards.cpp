#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int gcd(int a, int b)
{
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

bool hasGroupsSizeX(vector<int>& deck)
{
    int arr[10004];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < deck.size();++i)
        arr[deck[i]]++;

    // GCD
    int g = -1;
    for (int i = 0; i < 10004;++i)
    {
        if(arr[i])
        {
            if(g == -1)
                g = arr[i];
            else
                g = gcd(g, arr[i]);
        }
    }
    return g > 1;
}