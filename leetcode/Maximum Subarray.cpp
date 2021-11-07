#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int> nums)
{
    int sum = nums[0], mx = nums[0];
    for (int i = 1; i < nums.size();++i)
    {
        sum = (sum > 0) ? sum += nums[i] : nums[i];
        mx = max(mx, sum);
    }
    return mx;
}

int main()
{
    vector<int> vec = {-1, 0, -2, 10};
    cout << maxSubArray(vec);
    return 0;
}