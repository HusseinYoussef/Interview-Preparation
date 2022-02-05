#include <vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
    int n = nums.size(), ans = 0;
    for(int i = 0; i<32;++i)
    {
        int cnt = 0;
        for(int j = 0; j < n; ++j)
        {
            if(nums[j] & (1<<i))
                ++cnt;
        }
        if(cnt % 3)
            ans |= (1<<i);
    }
    return ans;
}
