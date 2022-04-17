#include <vector>

using namespace std;

int findBitonic(vector<int>& arr, int element)
{
    // find peak first
    int n = arr.size();
    // exclude index 0 and n-1 since peak should have elements on both sides
    int l = 0, r = n - 1, mid;
    while(r-l>1)
    {
        mid = l + (r - l) / 2;
        if(arr[mid] > arr[mid-1])
            l = mid;
        else
            r = mid;
    }

    // l = peak now
    int peakIdx = l;

    // Search in left part (increasing part)
    l = 0, r = peakIdx + 1;
    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(arr[mid] == element)
            return mid;
        
        if(arr[mid] > element)
            r = mid;
        else
            l = mid + 1;
    }

    // Search in right part (decreasing part)
    l = peakIdx, r = n;
    while(r - l > 1)
    {
        mid = l + (r - l) / 2;
        if(arr[mid] == element)
            return mid;
   
        if(arr[mid] < element)
            r = mid;
        else
            l = mid;
    }
    return -1;
}