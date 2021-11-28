#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    for (int i = 0; i < nums.size();++i)
    {   if(nums[abs(nums[i])-1]>0)
        {
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
    }
    vector<int> ans;
    for (int i = 0; i < nums.size();++i)
    {
        if(nums[i] > 0)
            ans.push_back(i + 1);
    }
    return ans;
}

int main()
{
    vector<int> vec = {4, 3, 2, 7, 8, 2, 3, 1};
    findDisappearedNumbers(vec);
    return 0;
}