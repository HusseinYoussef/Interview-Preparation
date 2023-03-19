#include <vector>

using namespace std;

int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen)
{
    int n = nums.size();

    int ans = 0;
    int l1 = 0, r1 = firstLen, sum1 = 0, s2 = 0;
    for(int i = 0;i<firstLen;++i)
        sum1 += nums[i];
    for(int i = 0;i<secondLen;++i)
        s2 += nums[i];

    while(r1 <= n)
    {
        int l2 = 0, r2 = secondLen, sum2 = s2;
        while(r2 <= n)
        {
            if(r2 <= l1 || l2 >= r1) // no overlapping
            {
                ans = max(ans, sum1 + sum2);
            }
            if(r2 == n)
                break;
            sum2 -= nums[l2++];
            sum2 += nums[r2++];
        }
        if (r1 == n)
            break;
        sum1 -= nums[l1++];
        sum1 += nums[r1++];
    }

    return ans;
}
