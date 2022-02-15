#include <vector>

using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr)
{
    int n = arr.size();
    vector<int> freq(1005, 0);
    for(int i = 0;i<n;++i)
        ++freq[arr[i]], --freq[target[i]];
    for(int i = 0;i<=1000;++i)
    {
        if(freq[i] != 0)
            return false;
    }
    return true;
}