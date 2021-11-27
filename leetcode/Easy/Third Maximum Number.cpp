#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int thirdMax(vector<int>& nums)
{
    int mx1 = -INT_MAX;
    int mx2 = -INT_MAX;
    int mx3 = -INT_MAX;
    for (int i = 0; i < nums.size();++i)
    {
        if(nums[i] == mx1 || nums[i] == mx2 ||nums[i] == mx3)
            continue;
        if(mx1 == -INT_MAX || nums[i] > mx1)
        {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = nums[i];
        }  
        else if(mx2 == -INT_MAX || nums[i] > mx2)
        {
            mx3 = mx2;
            mx2 = nums[i];
        }
        else if(mx3 == -INT_MAX || nums[i] > mx3)
            mx3 = nums[i];

    }
    return mx3 == -INT_MAX? mx1 : mx3;
}
int main()
{
    vector<int> vec = {3,2,1};
    cout << thirdMax(vec);
    return 0;
}