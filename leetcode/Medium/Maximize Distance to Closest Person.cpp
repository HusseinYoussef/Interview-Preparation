#include <iostream>
#include <vector>

using namespace std;

int maxDistToClosest(vector<int>& seats)
{
    int n = seats.size();
    int pre = 1e6;
    for(int i = 0;i<n;++i)
    {
        seats[i] |= (pre << 1);
        if(seats[i] & 1)
            pre = i;
    }
    pre = 1e6;
    int ans = 0;
    for(int i = n-1;i>=0;--i)
    {
        if((seats[i] & 1) == 0)
        {
            ans = max(ans, min(pre - i, abs(i - (seats[i] >> 1))));
        }
        else
            pre = i;
    }
    return ans;
}
