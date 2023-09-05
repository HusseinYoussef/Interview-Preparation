#include <vector>

using namespace std;

int Partition(vector<int>& nums, int l, int r)
{
    // last element
    int pivot = nums[r];

    int idx = l;

    for (int i = l; i<r;++i)
    {
        if (nums[i] < pivot)
            swap(nums[i], nums[idx++]);
    }

    swap(nums[idx], nums[r]);
    return idx;
}

void quickSort(vector<int>& nums, int l, int r)
{
    if (l >= r)
        return;
    
    int pi = Partition(nums, l, r);
    cout << pi;
    quickSort(nums, l, pi - 1);
    quickSort(nums, pi + 1, r);
}

void heapifyDown(vector<int>& nums, int i, int &n)
{
    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && nums[l] > nums[largest])
        largest = l;
        
    if (r < n && nums[r] > nums[largest])
        largest = r;

    if (largest != i)
    {
        swap(nums[i], nums[largest]);
        heapifyDown(nums, largest, n);
    }
}

void heapSort(vector<int>& nums)
{
    int n = nums.size();
    for (int i = n / 2 - 1; i>= 0; --i)
    {
        heapifyDown(nums, i, n);
    }

    for (int i = n-1;i>0;--i)
    {
        swap(nums[0], nums[i]);
        heapifyDown(nums, 0, i);
    }
}

void merge(vector<int>& nums, int l, int mid, int r)
{
    vector<int> left;
    vector<int> right;
    for (int i = l;i<=mid;++i)
        left.push_back(nums[i]);
    for (int i = mid+1;i<=r;++i)
        right.push_back(nums[i]);
    
    int idx = l;
    int idx1 = 0, idx2 = 0;
    while (idx1 < left.size() && idx2 < right.size())
    {
        if (left[idx1] < right[idx2])
            nums[idx++] = left[idx1++];
        else
            nums[idx++] = right[idx2++];
    }

    while (idx1 < left.size())
        nums[idx++] = left[idx1++];

    while (idx2 < right.size())
        nums[idx++] = right[idx2++];
}

void mergeSort(vector<int>& nums, int l, int r)
{
    if (l >= r)
        return;
    
    int mid = l + (r - l) / 2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    merge(nums, l, mid, r);
}

vector<int> sortArray(vector<int>& nums)
{
    int n = nums.size();
    mergeSort(nums, 0, n-1);
    return nums;
}
