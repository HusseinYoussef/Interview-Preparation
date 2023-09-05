#include <vector>

using namespace std;

bool checkPossibility(vector<int>& nums)
{
    int n = nums.size();

    bool f = 0;
    for (int i = 0; i<n-1;++i)
    {
        // non decreasing
        if (nums[i] > nums[i + 1])
        {
            if (f)
                return false;
            
            // try to make left element smaller if possible (if i+1 > i-1) not breaking the previous increasing order
            if (i == 0 || nums[i+1] >= nums[i-1])
                nums[i] = nums[i+1];
            // else we make the right element larger (we had no other choice)
            else
                nums[i+1] = nums[i];
            f = 1;
        }
    }

    return true;
}
