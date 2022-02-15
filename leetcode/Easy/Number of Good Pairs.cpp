#include <vector>

using namespace std;

int numIdenticalPairs(vector<int>& nums)
{
    int n = nums.size();
    int ans = 0;
    for(int i = 0;i<n;++i)
    {
        for(int j = i+1;j<n;++j)
        {
            ans += nums[i] == nums[j];
        }
    }
    return ans;
}