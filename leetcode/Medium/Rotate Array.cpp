#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& nums, int l, int r)
{
    while(l < r)
        swap(nums[l++], nums[r--]);
}

void rotate(vector<int>& nums, int k)
{
    // Reverse Trick O(N) Time, O(1) Space
    int n = nums.size();
    k = k % n;
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - k - 1);
    reverse(nums, 0, n - 1);
}