#include <iostream>
#include <vector>

using namespace std;

int numPairsDivisibleBy60(vector<int>& time)
{
    int n = time.size();
    int arr[502];
    memset(arr, 0, sizeof(arr));
    int ans = 0;
    for(int i =n-1;i>=0;--i)
    {
        int j = (time[i] / 60 + 1) * 60;
        while(j - time[i] <= 500)
        {
            ans += arr[j - time[i]];
            j+=60;
        }
        arr[time[i]]++;
    }
    return ans;
}
