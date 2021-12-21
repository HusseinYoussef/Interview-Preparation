#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int n = gas.size();
    int mx = -1;
    int idx = 0;
    for (int i = n - 1; i >= 0;--i)
    {
        if(i+1 < n)
            gas[i] += gas[i + 1], cost[i] += cost[i + 1];
        
        if(gas[i] - cost[i] > mx)
        {
            idx = i;
            mx = max(mx, gas[i] - cost[i]);
        }
    }
    if(cost[0] > gas[0])
        return -1;
    return idx;
}