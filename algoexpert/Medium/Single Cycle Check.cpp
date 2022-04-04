
/*
    Problem Statement

    You're given a circular array of integers where each integer represents a jump of its
    value in the array. For instance, the integer 2  represents a jump
    of two indices forward in the array; the integer 3  represents a jump of three indices backward in the array.

    Write a function that returns a boolean representing whether the jumps in the
    array form a single cycle. A single cycle occurs if, starting at any index in
    the array and following the jumps, every element in the array is visited
    exactly once before landing back on the starting index.
*/

#include <vector>
using namespace std;

bool hasSingleCycle(vector<int> array)
{
    int n = array.size();

    int vis = 0, curIdx = 0;
    while(vis < n)
    {
        if(vis > 0 && curIdx == 0)
            return false;

        ++vis;
        curIdx = ((curIdx + array[curIdx]) % n + n) % n;
    }
    return curIdx == 0;
}