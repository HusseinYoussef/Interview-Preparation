#include <vector>
#include <climits>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int diff = INT_MAX, ans = 0;
    for(int i = 0;i<n-2;++i)
    {
        int l = i+1, r = n-1;
        int sum = 0;
        while(l < r)
        {
            sum = nums[i] + nums[l] + nums[r];
            if(abs(sum - target) < diff)
            {
                diff = abs(sum - target);
                ans = sum;
            }
            if(sum > target)
                --r;
            else
                ++l;
        }
    }
    return ans;
}
