
/*
    Problem Statement

    Write a function that takes in an array of integers and returns a boolean
    representing whether the array is monotonic.
*/

#include "vector"
using namespace std;

bool isMonotonic(vector<int> array)
{
    int n = array.size();
    bool inc = 1, dec = 1;
    for (int i = 1; i < n;++i)
    {
        inc &= array[i] >= array[i - 1];
        dec &= array[i] <= array[i - 1];
    }
    return inc || dec;
}
