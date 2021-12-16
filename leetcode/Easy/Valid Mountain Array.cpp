#include <iostream>
#include <vector>

using namespace std;

bool validMountainArray(vector<int>& arr)
{
    if(arr.size() < 3)
        return false;

    bool f = 0;
    for (int i = 1; i < arr.size();++i)
    {
        if(arr[i] == arr[i-1])
            return false;
        if(f)
        {
            if(arr[i] >= arr[i-1])
                return false;
        }
        else
        {
            if(arr[i] <= arr[i-1])
                return false;
        }
        if(i < arr.size()-1 && arr[i] > arr[i-1] && arr[i] > arr[i+1])
            f = 1;
    }
    return f;
}