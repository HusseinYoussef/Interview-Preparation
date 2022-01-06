#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums)
{
    int n = nums.size();
    int mx = 1000, l = 0, r = n - 1;
    for (int i = n - 2; i >= 0;--i)
    {
        if(nums[i] < nums[i+1])
        {
            int idx = -1;
            for (int j = i + 1; j < n;++j)
            {
                // in case of repeated numbers, we want the last one of them to keep the subbarray in descending order
                if(nums[j] <= mx && nums[j] > nums[i])
                {
                    idx = j;
                    mx = nums[j];
                }
            }
            swap(nums[idx], nums[i]);
            l = i + 1;
            break;
        }
    }
    while(l < r)
        swap(nums[l++], nums[r--]);
}