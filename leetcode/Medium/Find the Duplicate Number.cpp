#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums)
{
    // Move each element to its right place O(N), or use Negative Marking (in case of the array can be modified)
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

    // Or consider it as a linked list, and find where the cycle begins, there is a guarantee that there is a cycle
    // O(N) time, O(1) Space
    // int n = nums.size();
    // int slow = 0, fast = 0;

    // do
    // {
    //    slow = nums[slow];
    //    fast = nums[nums[fast]];
    // } while(slow != fast);
    
    // slow = 0;
    // while (slow != fast)
    // {
    //    slow = nums[slow];
    //    fast = nums[fast];
    // }

    // return slow;
}
