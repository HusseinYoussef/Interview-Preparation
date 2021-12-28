#include <iostream>
#include <vector>

using namespace std;

vector<int> replaceElements(vector<int>& arr)
{
    int mx = -1;
    for(int i = arr.size()-1;i>=0;--i)
    {
        int tmp = arr[i];
        arr[i] = mx;
        mx = max(mx, tmp);
    }
    return arr;
}
