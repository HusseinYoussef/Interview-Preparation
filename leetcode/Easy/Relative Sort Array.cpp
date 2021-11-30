#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
{
    // O(N+M) Time & O(1) Space
    
    int freq[1005];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < arr1.size();++i)
        ++freq[arr1[i]];

    int idx = 0;
    for (int i = 0; i < arr2.size();++i)
    {
        while(freq[arr2[i]])
        {
            arr1[idx++] = arr2[i];
            --freq[arr2[i]];
        }
    }
    for (int i = 0; i < 1005;++i)
    {   
        while(freq[i])
        {
            arr1[idx++] = i;
            --freq[i];
        }
    }
    return arr1;
}