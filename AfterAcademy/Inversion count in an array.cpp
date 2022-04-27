#include <vector>

using namespace std;

int n;
int merge(vector<int>& arr, int l, int mid, int r)
{
    vector<int> tmp;

    int inversions = 0;
    int i = l, j = mid+1;
    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j])
            tmp.push_back(arr[i++]);
        else
        {
            inversions += mid - i + 1;
            tmp.push_back(arr[j++]);
        }
    }
    while(i <= mid)
        tmp.push_back(arr[i++]);
    while(j <= r)
        tmp.push_back(arr[j++]);

    for (int i = l, j = 0; i <= r;++i,++j)
        arr[i] = tmp[j];
    return inversions;
}

int mergesort(vector<int>& arr, int l, int r)
{
    if(r <= l)
        return 0;

    int inversions = 0;
    int mid = l + (r - l) / 2;
    inversions += mergesort(arr, l, mid) + mergesort(arr, mid+1, r);
    inversions += merge(arr, l, mid, r);
    return inversions;
}

int inversionCount(vector<int>& arr)
{
    n = arr.size();
    return mergesort(arr, 0, n - 1);
}