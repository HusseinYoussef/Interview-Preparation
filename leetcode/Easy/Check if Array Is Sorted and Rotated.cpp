#include <vector>

using namespace std;

bool check(vector<int>& nums)
{
    int n = nums.size();
    int flip = 0, mn = nums[0];
    for(int i = 1;i<n;++i)
    {
        if(nums[i] < nums[i-1])
            ++flip;
        if(flip > 1 || (flip && nums[i] > mn))
            return false;                
    }
    return true;
}