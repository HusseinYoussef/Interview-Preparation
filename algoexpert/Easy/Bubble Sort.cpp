
/*
    Problem Statement

    Sort in-place using Bubble Sort
*/

#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array)
{
    int n = array.size();
    bool f = 1;
    int cnt = 0;
    while (f)
    {
        f = 0;
        // at each iteration of the while loop, we keep putting the next largest number at its right place
        for (int i = 1; i < n-cnt;++i)
        {
            if(array[i] < array[i-1])
            {
                f = 1;
                swap(array[i], array[i - 1]);
            }
        }
        ++cnt;
    }
    return array;
}
