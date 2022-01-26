#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums)
{
    int n = nums.size();
    if(n == 1)
        return 0;
    int ans = 0, tmp = 0, dis = nums[0];
    for(int i =0;i<=min(dis, n-1);++i)
    {
        tmp = max(tmp, i+nums[i]);
        if(i == min(dis, n-1))
        {
            dis = tmp;
            ++ans;
        }
    }
    return ans;
}
