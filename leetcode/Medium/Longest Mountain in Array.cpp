#include <vector>

using namespace std;

int longestMountain(vector<int>& arr)
{
    int n = arr.size();
    int ans = 0;
    for (int i = 1; i < n - 1;++i)
    {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
        {
            int l = i - 1, r = i + 1;
            while(l >= 0 && arr[l] < arr[l+1])
                --l;
            while(r < n && arr[r] < arr[r-1])
                ++r;
            ans = max(ans, r - l - 1); // (r-1) - (l+1) + 1
        }
    }
    return ans;
}

// Simulation
// int longestMountain(vector<int> arr)
// {
//     int n = arr.size();
//     int ans = 0;
//     for (int i = 0; i < n - 1;++i)
//     {
//         // walk up
//         int st = i;
//         while(i+1 < n && arr[i] < arr[i+1])
//             ++i;

//         if(i == st)
//             continue;
//         if(i+1 < n && arr[i] > arr[i+1]) // possible peak
//         {
//             // walk down
//             while (i+1 < n && arr[i] > arr[i+1])
//                 ++i;
//             ans = max(ans, i - st + 1);
//             --i;
//         }
//     }
//     return ans;
// }