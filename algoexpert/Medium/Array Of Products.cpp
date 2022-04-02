
/*
    Problem Statement (Array Product without self)

    Write a function that takes in a non-empty array of integers and returns an
    array of the same length, where each element in the output array is equal to
    the product of every other number in the input array.

    Note that you're expected to solve this problem without using division.
*/

#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array)
{
    int n = array.size();
    // left cumulative product
    vector<int> l(n, 1);
    int prod = 1;
    for (int i = 0; i < n;++i)
    {
        l[i] = prod;
        prod *= array[i];
    }
    // right cumulative product
    prod = 1;
    for (int i = n - 1; i >= 0;--i)
    {
        l[i] *= prod;
        prod *= array[i];
    }
    return l;
}
