#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr)
{
    // Ternary Search    Can be solved using binary search too
    int l = 0, r = arr.size() - 1, mid1, mid2;
    while(l<r)
    {
        mid1 = l + (r - l) / 3;
        mid2 = r - (r - l) / 3;
        if(arr[mid2-1] > arr[mid2])
            r = mid2 - 1;
        else if(arr[mid1+1] > arr[mid1])
            l = mid1 + 1;
    }
    return l;
}

int main()
{
    vector<int> vec = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    peakIndexInMountainArray(vec);
    return 0;
}