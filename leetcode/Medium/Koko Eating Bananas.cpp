#include <iostream>
#include <vector>

using namespace std;

bool ok(vector<int>& piles, int k, int h)
{
    int ans = 0;
    for(int i = 0;i<piles.size();++i)
    {
         // ceil
         ans += (piles[i] + k - 1)/ k;
    }
    return ans <= h;
}

int minEatingSpeed(vector<int>& piles, int h)
{
    int l = 0, r = 1e9+1, mid;
    while(r-l > 1)
    {
        mid = l + (r-l) / 2;
        if(ok(piles, mid, h))
            r = mid;
        else
            l = mid;
    }
    return r;
}
