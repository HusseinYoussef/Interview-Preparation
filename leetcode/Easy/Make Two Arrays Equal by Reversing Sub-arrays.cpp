#include <vector>

using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr)
{
    int n = arr.size();
    vector<int> freq1(1005, 0);
    vector<int> freq2(1005, 0);
    for(int i = 0;i<n;++i)
        ++freq1[arr[i]], ++freq2[target[i]];
    for(int i = 0;i<=1000;++i)
    {
        if(freq1[i] != freq2[i])
            return false;
    }
    return true;
}