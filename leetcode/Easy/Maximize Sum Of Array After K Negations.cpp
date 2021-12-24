#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k)
{
    int sum = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n;++i)
    {
        if(nums[i] < 0)
        {
            if(k)
            {
                --k;
                sum -= nums[i];
            }
            else
                sum += nums[i];
        }
        else if(nums[i] == 0)
            k = 0;
        else
        {
            if(k & 1)
            {
                if(i > 0 && abs(nums[i-1]) < nums[i])
                    sum = sum - abs(nums[i - 1]) * 2 + nums[i];
                else
                    sum -= nums[i];
                k = 0;
            }
            else
                sum += nums[i];
        }
    }
    if(k & 1)
        sum -= abs(nums[n - 1]) * 2;
    return sum;
}