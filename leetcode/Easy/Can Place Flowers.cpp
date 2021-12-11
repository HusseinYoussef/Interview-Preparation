#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    int ans = 0;
    for(int i=0;i<flowerbed.size();++i)
    {
        if(flowerbed[i] == 0)
        {
            if((i-1 < 0 || flowerbed[i-1] == 0) && (i+1 >= flowerbed.size() || flowerbed[i+1] == 0))
            {
                ++ans;
                flowerbed[i] = 1;
            }
        }
        if(ans >= n) 
            return true;
    }
    return ans >= n;
}
