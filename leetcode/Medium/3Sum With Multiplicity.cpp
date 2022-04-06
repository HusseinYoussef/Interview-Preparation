#include <vector>
#include <algorithm>

using namespace std;

int threeSumMulti(vector<int>& arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int>freq(105, 0);
    for(int i = 0;i<n;++i)
        ++freq[arr[i]];
        
    long ans = 0, mod = 1e9+7;
    for(int i = 0;i<n-2;++i)
    {
        if(i > 0 && arr[i] == arr[i-1])
            continue;
        int l = i+1, r = n-1, val = target - arr[i];
        while(l < r)
        {
            int sum = arr[l] + arr[r];
            if(sum == val)
            {
                long c;
                if(arr[i] == arr[l] && arr[i] == arr[r])
                {
                    c = freq[arr[i]];
                    ans += c * (c-1) * (c-2) / 6;
                }
                else if(arr[i] == arr[l])
                {
                    c = freq[arr[i]];
                    ans += freq[arr[r]] * c * (c-1) / 2;
                }
                else if(arr[l] == arr[r])
                {
                    c = freq[arr[l]];
                    ans += freq[arr[i]] * c * (c-1) / 2;
                }
                else
                {
                    ans += (long)freq[arr[i]] * freq[arr[l]] * freq[arr[r]];
                }
                ans %= mod;
                ++l, --r;
                // for duplicates
                while(r > l && arr[r] == arr[r+1])
                    --r;
                while(l < r && arr[l] == arr[l-1])
                    ++l;
            }
            else if(sum < val)
                ++l;
            else
                --r;
        }
    }
    return ans;
}
