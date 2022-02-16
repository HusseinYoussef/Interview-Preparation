#include <vector>

using namespace std;

int sumOddLengthSubarrays(vector<int>& arr)
{
    int n = arr.size();
    vector<int> pref(n, 0);
    int sum = 0;
    for (int i = 0; i < n;++i)
    {
        sum += arr[i];
        pref[i] = sum;
    }
    for (int s = 3; s <= n;s+=2)
    {
        for (int i = 0; i <= n-s; ++i)
        {
            sum += pref[i + s - 1] - pref[i] + arr[i];
        }
    }
    return sum;
}