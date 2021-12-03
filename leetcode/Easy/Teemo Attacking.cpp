#include <iostream>
#include <vector>

using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration)
{
    int last = -1, ans = 0;
    for (int i = 0; i < timeSeries.size();++i)
    {
        ans += min(duration, timeSeries[i] + duration - 1 - last);
        last = timeSeries[i] + duration - 1;
    }
    return ans;
}