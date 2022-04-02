
/*
    Problem Statement

    You're given an array of integers and an integer. Write a function that moves
    all instances of that integer in the array to the end of the array and returns
    the array.

    The function should perform this in place (i.e., it should mutate the input
    array) and doesn't need to maintain the order of the other integers.
*/

#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove)
{
    int n = array.size();
    int r = n - 1;
    // move each element to its right place
    for (int i = 0; i < r;++i)
    {
        while (array[i] == toMove && i < r)
            swap(array[i], array[r--]);
    }
    return array;
}