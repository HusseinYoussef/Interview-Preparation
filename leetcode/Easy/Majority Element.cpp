#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums)
{
    // Boyer-Moore Majority Voting Algorithm

    int cand = -1;
    int votes = 0;
    for(int i:nums)
    {
        if(votes == 0)
            cand = i;
        votes += cand == i ? +1 : -1;
    }
    return cand;

    // Counting Bits

    // vector<int> bits(32, 0);
    // for (int i = 0; i < nums.size(); ++i)
    // {
    //     int tmp = nums[i];
    //     int j = 0;
    //     while(tmp && j < 32)
    //     {
    //         bits[j++] += tmp & 1;
    //         tmp >>= 1;
    //     }
    // }
    // int ans = 0;
    // for (int i = 0; i < 32;++i)
    // {
    //     if(bits[i] > nums.size()/2)
    //     {
    //         ans |= 1 << i;
    //     }
    // }
    // return ans;
}

int main()
{
    vector<int> nums = {-1, 1, 1, 1, 2, 1};
    cout << majorityElement(nums);
    return 0;
}