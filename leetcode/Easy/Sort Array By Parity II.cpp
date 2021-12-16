#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums)
{
    int l = 0, r = nums.size() - 1;
    while(l < nums.size() && r >= 0)
    {
        if((nums[l] & 1) == 1 && (nums[r] & 1) == 0)
            swap(nums[l], nums[r]);
        l += ((nums[l] & 1) == 0)?2:0;
        r -= ((nums[r] & 1) == 1)?2:0;
    }
    return nums;

    int e = 0, o = 1;
    for (int i = 0; i < nums.size();++i)
    {
        int val = ((1 << 10) - 1) & nums[i];
        if(val & 1)
        {
            nums[o] |= (val << 10);
            o += 2;
        }
        else
        {
            nums[e] |= (val << 10);
            e += 2;
        }
    }
    for (int i = 0; i < nums.size();++i)
        nums[i] >>= 10;
    return nums;
}

int main()
{
    vector<int> vec = {4,2,5,7};
    sortArrayByParityII(vec);
    return 0;
}