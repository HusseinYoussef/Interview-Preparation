#include <iostream>
#include <vector>

using namespace std;

vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes)
{
    int sum1 = 0, sum2 = 0;
    unordered_map<int, bool>arr;
    for(int i =0;i<aliceSizes.size();++i)
        sum1 += aliceSizes[i], arr[aliceSizes[i]]=1;
    for(int i =0;i<bobSizes.size();++i)
        sum2 += bobSizes[i];

    int tot = (sum1 + sum2) / 2;
    vector<int>ans;
    for(int i=0;i<bobSizes.size();++i)
    {
        int need = abs(tot - (sum2-bobSizes[i]));
        if(arr[need] && sum1 + bobSizes[i] - need == tot)
        {
            ans = {need, bobSizes[i]};
            break;
        }
    }
    return ans;
}
