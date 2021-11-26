#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
    int idx = 0;
    for (int i = 0; i < nums.size();++i)
    {
        if(nums[i] != 0)
        {
            if(i != idx)
                nums[idx] = nums[i];
            ++idx;
        }
    }
    for (int i = idx; i < nums.size();++i)
        nums[i] = 0;
}

int main()
{
    return 0;
}