
/*
    Problem Statement

    Write a function that takes in an array of at least three integers and,
    without sorting the input array, returns a sorted array of the three largest
    integers in the input array.
*/

#include <vector>
#include <climits>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array)
{
    int n = array.size();
    int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
    for (int i = 0; i < n;++i)
    {
        if(array[i] >= mx1)
        {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = array[i];
        }
        else if(array[i] >= mx2)
        {
            mx3 = mx2;
            mx2 = array[i];
        }
        else if(array[i] > mx3)
            mx3 = array[i];
    }
    return {mx3, mx2, mx1};
}
