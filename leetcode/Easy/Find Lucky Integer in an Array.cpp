#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int findLucky(vector<int>& arr)
{
    int freq[505];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < arr.size();++i)
        freq[arr[i]]++;
    for (int i = 500; i > 0;--i)
    {
        if(freq[i] == i)
            return i;
    }
    return -1;
}