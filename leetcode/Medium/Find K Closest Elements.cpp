#include <iostream>
#include <vector>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    // O(N)
    int n = arr.size();
    int d = n - k;
    int l = 0, r = n - 1;
    while(d)
    {
        if(abs(arr[r] - x) >= abs(arr[l] - x))
            --r;
        else
            ++l;
        --d;
    }
    vector<int> ans;
    for (int i = l; i <= r;++i)
        ans.push_back(arr[i]);
    return ans;

    // Binary Search O(log(n-k)+k)
    // case 1: x - A[mid] < A[mid + k] - x, need to move window go left
    // -------x----A[mid]-----------------A[mid + k]----------

    // case 2: x - A[mid] < A[mid + k] - x, need to move window go left again
    // -------A[mid]----x-----------------A[mid + k]----------

    // case 3: x - A[mid] > A[mid + k] - x, need to move window go right
    // -------A[mid]------------------x---A[mid + k]----------

    // case 4: x - A[mid] > A[mid + k] - x, need to move window go right
    // -------A[mid]---------------------A[mid + k]----x------
    int n = arr.size();
    int l = 0, r = n - k, mid;
    // [l, r]
    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(x - arr[mid] > arr[mid+k] - x)
            l = mid + 1;
        else
            r = mid;
    }
    vector<int> ans;
    for (int i = 0; i < k;++i)
        ans.push_back(arr[l + i]);
    return ans;
}