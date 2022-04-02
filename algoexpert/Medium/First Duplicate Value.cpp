
/*
    Problem Statement

    Given an array of integers between 1 and n inclusive, where n is the length of the array, write a function
    that returns the first integer that appears more than once (when the array is read from left to right).

    In other words, out of all the integers that might occur more than once in the
    input array, your function should return the one whose first duplicate value
    has the minimum index.

    
    If no integer appears more than once, your function should return -1
    Note that you're allowed to mutate the input array.
*/

#include <iostream>
#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array)
{
    int n = array.size();
    // Negative marking method
    for (int i = 0; i < n;++i)
    {
        int idx = abs(array[i]) - 1;
        if(array[idx] < 0)
            return abs(array[i]);
        else
            array[idx] = -array[idx];
    }
    return -1;
}