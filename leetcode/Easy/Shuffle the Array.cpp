#include <iostream>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n)
{
    // Since each number is <= 1000 (using only 10 bits) then we can store 2 numbers using the same binary representation (32-bit int)
    // (y1, x1), (y2, x2) ...
    for (int i =0, j = n; i < n;++i,++j)
        nums[j] = nums[i] | (nums[j] << 10);

    for (int i = 0, j = n; j < 2 * n; i += 2, ++j)
    {
        nums[i] = ((1 << 10) - 1) & nums[j];
        nums[i+1] = nums[j] >> 10;
    }
    return nums;
}