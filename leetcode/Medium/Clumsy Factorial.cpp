#include <vector>

using namespace std;

int clumsy(int n)
{
    vector<int> nums = {n};
    // *  /  +   -
    for (int i = n - 1, j = 0; i >= 1; --i, j = (j + 1) % 4)
    {
        if(j < 2)
        {
            int tmp = nums.back();
            nums.pop_back();
            // * or /
            nums.push_back((j == 0) ? tmp * i : tmp / i);
        }
        else // + or -
            nums.push_back((j == 2) ? i : -i);
    }
    int ans = 0;
    for (int i = 0; i < nums.size();++i)
        ans += nums[i];
    return ans;
}