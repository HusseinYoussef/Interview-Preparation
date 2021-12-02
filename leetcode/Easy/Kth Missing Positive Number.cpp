#include <iostream>
#include <vector>

using namespace std;

// int findKthPositive(vector<int>& arr, int k)
// {
//     int pre = 0;
//     for (int i = 0; i < arr.size();++i)
//     {
//         int miss = arr[i] - pre - 1;
//         if(miss>=k)
//             return pre + k;
//         k -= miss;
//         pre = arr[i];
//     }
//     return pre + k;
// }

int findKthPositive(vector<int>& arr, int k)
{
    // FFFFFFTTTTTT want last F
    int l = 0, r = arr.size(), mid;
    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(arr[mid] - mid - 1 >= k)
            r = mid;
        else
            l = mid+1;
    }
    // First T is l
    // ans (l - 1) = A[l-1] + k - (A[l-1]-(l-1+1)) = l + k
    return l + k;
}

int main()
{
    vector<int> vec = {2, 3, 4, 7, 11};
    findKthPositive(vec, 5);
    return 0;
}