#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumProduct(vector<int>& nums)
{
    int mx1 = -2000, mx2 = -2000, mx3 = -2000;
    int mn1 = 2000, mn2 = 2000;
    for (int i = 0; i < nums.size();++i)
    {
        if(nums[i] >= mx1)
        {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = nums[i];
        }
        else if(nums[i] >= mx2)
        {
            mx3 = mx2;
            mx2 = nums[i];
        }
        else if(nums[i] >= mx3)
            mx3 = nums[i];
        if(nums[i] <= mn1)
        {
            mn2 = mn1;
            mn1 = nums[i];
        }
        else if(nums[i] <= mn2)
            mn2 = nums[i];
    }
    return max(mx1 * mx2 * mx3, mx1 * mn1 * mn2);

    // O(n log n)
    int n = nums.size();
    sort(nums.begin(), nums.end());
    return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[n - 1] * nums[1] * nums[0]);
}

int main()
{
    vector<int> vec = {-100, -98, -1, 2, 3, 4};
    maximumProduct(vec);
    return 0;
}