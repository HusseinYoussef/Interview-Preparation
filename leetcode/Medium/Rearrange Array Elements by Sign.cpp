#include <vector>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums)
{
    int n = nums.size();
    
    vector<int> ans(n);
    int positiveIdx = 0, negativeIdx = 1;
    for(int i = 0;i<n;++i)
    {
        if(nums[i] > 0)
        {
            ans[positiveIdx] = nums[i];
            positiveIdx += 2;
        }
        else
        {
            ans[negativeIdx] = nums[i];
            negativeIdx += 2;
        }
    }
    return ans;
}