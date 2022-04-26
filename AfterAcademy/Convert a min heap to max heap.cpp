#include <vector>

using namespace std;

void heapify(vector<int>& arr, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

vector<int> convertToMaxHeap(vector<int>& arr)
{
    // O(N) search for proof
    int n = arr.size();
    // heapify internal nodes in a bottom up manner, start with nodes near the leaves, since leaves satisfy heap properties
    for (int i = n / 2 - 1; i >= 0;--i)
    {
        heapify(arr, i, n);
    }
    return arr;
}