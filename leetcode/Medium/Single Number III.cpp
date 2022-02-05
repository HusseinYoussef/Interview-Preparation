#include <vector>

using namespace std;

vector<int> singleNumber(vector<int>& nums)
{
    int n = nums.size();
    int diff = 0;
    for(int i =0;i<n;++i)
        diff ^= nums[i];

    // now diff is a ^ b where a, b are the numbers we are looking for
    vector<int> ans = {0,0};
    // get any set bit e.g. the last set bit
    // guaranteed that there will be 1 set bit since a, b are distinct/different

    // Corner Case when diff = INT_MIN we cant get -INT_MIN (overflow)
    // so -INT_MIN = INT_MIN so diff remains the same
    if(diff != INT_MIN)
        diff &= -diff;


    // so say a has this bit off(0) and b has this bit set(1)
    // split the nums to 2 groups (nums with this bit=0), (nums with this bit set to 1), so a will belong to one group and b will belong to the other group

    // now for each group solve the single number problem a.k.a normal xor

    for(int i =0;i<n;++i)
    {
        // group with that bit set
        if(nums[i] & diff)
            ans[1] ^= nums[i];
        // group with that bit off
        else
            ans[0] ^= nums[i];
    }
    return ans;
}
