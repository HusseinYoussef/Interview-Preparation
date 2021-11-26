#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
    // Using Sum
    
    // int sum = nums.size() * (1 + nums.size()) / 2;
    // for (int i = 0; i < nums.size(); ++i)
    //     sum -= nums[i];
    // return sum;
    
    // Using XOR
    
    int ans = 0;
    for (int i = 0; i < nums.size();++i)
    {
        ans ^= (i + 1);
        ans ^= nums[i];
    }
    return ans;
}
int main()
{
    return 0;
}