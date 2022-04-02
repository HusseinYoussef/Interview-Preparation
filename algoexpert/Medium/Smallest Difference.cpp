
/*
    Problem Statement

    Write a function that takes in two non-empty arrays of integers, finds the
    pair of numbers (one from each array) whose absolute difference is closest to
    zero, and returns an array containing these two numbers, with the number from
    the first array in the first position.
    
    Note that the absolute difference of two integers is the distance between
    them on the real number line. For example, the absolute difference of -5 and 5
    is 10, and the absolute difference of -5 and -4 is 1.
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo)
{
    int n = arrayOne.size(), m = arrayTwo.size();

    // O(nlogn + mlogm)
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());

    int cand1 = 1e8, cand2 = -1e8;
    int idx1 = 0, idx2 = 0;
    while(idx1 < n && idx2 < m)
    {
        if(abs(arrayOne[idx1] - arrayTwo[idx2]) < abs(cand1 - cand2))
        {
            cand1 = arrayOne[idx1];
            cand2 = arrayTwo[idx2];
        }
        if(arrayOne[idx1] <= arrayTwo[idx2])
            ++idx1;
        else
            ++idx2;
    }
    return {cand1, cand2};
}