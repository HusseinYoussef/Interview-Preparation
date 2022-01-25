#include <vector>

using namespace std;

bool validMountainArray(vector<int>& arr)
{
    int n = arr.size();
    if(n < 3)
        return false;
    int i = 1;
    bool l = 0, r = 0;
    while(i < n && arr[i] > arr[i-1])
        ++i, l = 1;
    while(i < n && arr[i] < arr[i-1])
        ++i, r = 1;
    return i == n && l && r;
}
