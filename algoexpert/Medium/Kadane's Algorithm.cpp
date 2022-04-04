
/*
    Problem Statement

    Write a function that takes in a non-empty array of integers and returns the
    maximum sum that can be obtained by summing up all of the integers in a
    non-empty subarray of the input array. A subarray must only contain adjacent
    numbers (numbers next to each other in the input array).
*/

#include <vector>
#include <climits>
using namespace std;

int kadanesAlgorithm(vector<int> array)
{
    int n = array.size();
    int sum = 0, ans = INT_MIN;
    for (int i = 0; i < n;++i)
    {
        sum = max(sum, 0);
        sum += array[i];
        ans = max(ans, sum);
    }
    return ans;
}