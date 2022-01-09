#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums)
{
    // Move each element to its right place O(N)
    // for (int i = 0; i < nums.size();++i)
    // {
    //     while(nums[i] != nums[nums[i] - 1])
    //             swap(nums[i], nums[nums[i] - 1]);

    // }
    // return nums[nums.size() - 1];

    // O(N log N)
    int l = 1, r = nums.size() - 1, mid;
    while(l < r)
    {
        mid = l + (r - l) / 2;
        int cnt = 0;
        for (int i = 0; i < nums.size();++i)
        {
            if(nums[i] <= mid)
                ++cnt;
        }
        if(cnt > mid)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}