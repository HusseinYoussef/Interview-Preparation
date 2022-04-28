#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int n = gas.size();

    // If we cant trip from Station A to Station B, we cant trip from any station in between A..B to B
    // So no point to try starting at any point between A and B
    // Say Station C is in between A, B. Since we could travel from A to C, we may have tank >= 0 at C
    // if tank is 0, then starting at C is the same as starting at A (no point to start at C)
    // if tank is > 0, then starting at C is WORSE than starting at A. Since this is equivlent to starting at C with +ve tank
    // which is better than stating at C with 0 tank. (start at C with 0 tank or +ve tank?)
    // So we skip all stations in between A and B

    // first valid station is the answer, since if there is a valid station later, we may have tank >= 0 at that later station
    
    int start = 0, tank = 0, total = 0;
    for (int i = 0; i < n;++i)
    {
        tank += gas[i] - cost[i];
        total += gas[i] - cost[i];
        // cant make it to i+1
        if(tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }

    if(total < 0)
        return -1;
    return start;
}