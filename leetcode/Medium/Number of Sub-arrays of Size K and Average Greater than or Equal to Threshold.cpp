#include <iostream>
#include <vector>

using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold)
{
    int n = arr.size();

    int ans = 0;
    int sum = 0;
    for(int i = 0;i<n;++i)
    {
        if(i >= k)
            sum -= arr[i-k];
        sum += arr[i];

        if(i >= k-1 && sum / k >= threshold)
            ++ans;
    }
    return ans;
}
