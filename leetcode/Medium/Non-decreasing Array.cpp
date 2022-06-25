#include <vector>
#include <climits>

using namespace std;

bool checkPossibility(vector<int>& nums)
{
    int n = nums.size();

    int mn = INT_MAX;
    int f1 = 0;
    int mx = INT_MIN;
    int f2 = 0;
    for (int i = n-1, j = 0; i >= 0;--i, ++j)
    {
        if(nums[i] > mn)
            ++f1;
        if(nums[j] < mx)
            ++f2;
        if(f1 > 1 && f2 > 1)
            return false;
        mn = min(mn, nums[i]);
        mx = max(mx, nums[j]);
    }
    return f1 <= 1 || f2 <= 1;
}