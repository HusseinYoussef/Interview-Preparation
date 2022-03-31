
/*
    Problem Statement

    Write a function that takes in a non-empty array of integers (+ve and -ve) that are sorted
    in ascending order and returns a new array of the same length with the squares
    of the original integers also sorted in ascending order.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquaredArray(vector<int> array)
{
    int n = array.size();
    vector<int> ans(n);
    int l = 0, r = n - 1;
    int idx = n - 1;
    while(l <= r)
    {
        if(abs(array[r]) >= abs(array[l]))
        {
            ans[idx] = array[r] * array[r];
            --r;
        }
        else
        {
            ans[idx] = array[l] * array[l];
            ++l;
        }
        --idx;
    }
    return ans;
}