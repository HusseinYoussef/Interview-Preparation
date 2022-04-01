
/*
    Problem Statement

    Sort using Selection Sort
*/
#include <vector>
#include <climits>

using namespace std;

vector<int> selectionSort(vector<int> array)
{
    int n = array.size();
    for (int i = 0; i < n;++i)
    {
        int mn = INT_MAX, idx = -1;
        for (int j = i; j < n;++j)
        {
            if(array[j] < mn)
            {
                idx = j;
                mn = array[j];
            }
        }
        swap(array[i], array[idx]);
    }
    return array;
}
