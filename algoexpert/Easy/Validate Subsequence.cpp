
/*
    Problem Statement

    Given two non-empty arrays of integers, write a function that determines
    whether the second array is a subsequence of the first one.

*/

#include <vector>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
    int n = array.size(), m = sequence.size();
    int j = 0;
    for (int i = 0; i < n && j < m;++i)
    {
        if(array[i] == sequence[j])
            ++j;
    }
    return j == m;
}