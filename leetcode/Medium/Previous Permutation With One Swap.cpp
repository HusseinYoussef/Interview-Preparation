#include <vector>

using namespace std;

vector<int> prevPermOpt1(vector<int>& arr)
{
    int n = arr.size();
    // we need to swap a big element with another biggest smaller element, then the prefix is minimally decreased
    // from right to left, find first i > i+1, then the right side is sorted.
    // try to replace i with the biggest element < i on its rightside;
    int i;
    for (i = n - 2; i >= 0;--i)
    {
        // first element that has sorted subarray as its rightside
        if(arr[i] > arr[i+1])
            break;
    }
    if(i >= 0)
    {
        // find the largest element smaller than i
        int l = i, r = n, mid;
        while(r-l>1)
        {
            mid = l + (r - l) / 2;
            if(arr[mid] >= arr[i])
                r = mid;
            else
                l = mid;
        }
        // if there are duplicates we want the first one
        while(l-1 >= 0 && arr[l-1] == arr[l])
            --l;
        swap(arr[i], arr[l]);
    }
    return arr;
}