
/*
    Problem Statement

    Write a function that takes in an array of integers and returns the length of
    the longest peak in the array.

    A peak is defined as adjacent integers in the array that are strictly increaseing then strictly decreasing
*/

#include <vector>
using namespace std;

int longestPeak(vector<int> array)
{
    int n = array.size();
    int ans = 0;
    for (int i = 1; i < n - 1;++i)
    {
        if(array[i] > array[i-1] && array[i] > array[i+1])
        {
            int l = i - 1, r = i + 1;
            while(l >= 0 && array[l] < array[l+1])
                --l;
            while(r < n && array[r] < array[r-1])
                ++r;
            ans = max(ans, r - l - 1); // (r-1) - (l+1) + 1
        }
    }
    return ans;
}