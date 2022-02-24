#include <vector>
#include <algorithm>

using namespace std;

int triangleNumber(vector<int>& nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int c = n - 1; c >= 2;--c)
    {
        // if a + b > c, then because of the sorting a + c > b and b + c > a
        // then all combinations between a, b work since they still smaller than b
        int a = 0, b = c - 1;
        while(a < b)
        {
            if(nums[a] + nums[b] > nums[c])
            {
                ans += b - a;
                --b;
            }
            else
                ++a;
        }
    }
    return ans;
}