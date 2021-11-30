#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
{
    int freq[1005];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < arr1.size();++i)
        ++freq[arr1[i]];
    vector<int> ans;
    for (int i = 0; i < arr2.size();++i)
    {
        while(freq[arr2[i]])
        {
            ans.push_back(arr2[i]);
            --freq[arr2[i]];
        }
    }
    for (int i = 0; i < 1005;++i)
    {   
        while(freq[i])
        {
            ans.push_back(i);
            --freq[i];
        }
    }
    return ans;
}