#include <iostream>
#include <vector>

using namespace std;

int findSpecialInteger(vector<int>& arr)
{
    int s = arr.size()/4;
    int cnt = 1, ans = arr[0];
    for(int i = 1;i<arr.size();++i)
    {
        if(arr[i] != arr[i-1])
            cnt = 0;
        ++cnt;
        if(cnt > s)
            ans = arr[i];
    }
    return ans;
}
