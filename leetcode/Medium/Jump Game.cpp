#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums)
{
    int dis = 0, n = nums.size();
    for(int i =0;i <= dis; ++i)
    {
        dis = max(dis, i+nums[i]);
        if(dis >= n-1)
            return true;
    }
    return false;
}
