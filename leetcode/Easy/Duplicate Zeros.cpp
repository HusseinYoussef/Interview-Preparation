#include <iostream>
#include <vector>

using namespace std;

void duplicateZeros(vector<int>& arr)
{
    int n = arr.size();
    int z = 0, cnt = 0;
    bool f;
    for (int i = 0; i < n;++i)
    {
        cnt += (arr[i] == 0) + 1;
        z += arr[i] == 0;
        if(cnt >= n)
        {
            // to know if there is a zero that will not be repeated
            f = (z * 2 + (i + 1 - z)) > n;
            break;
        }
    }
    for (int i = n - z - 1 + f, idx = n - 1; i >= 0;--i)
    {
        arr[idx--] = arr[i];
        if(arr[i] == 0)
        {
            // last zero may not be repeated
            if(!f)
                arr[idx--] = arr[i];
            f = 0;
        }
    }
}