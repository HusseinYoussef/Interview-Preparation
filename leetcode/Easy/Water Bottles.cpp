#include <iostream>

using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    int ans = numBottles;
    while(numBottles >= numExchange)
    {
        int full = numBottles / numExchange;
        ans += full;
        numBottles = full + numBottles % numExchange;
    }
    return ans;
}