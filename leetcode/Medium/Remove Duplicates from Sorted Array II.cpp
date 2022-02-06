#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int n = nums.size();
    int idx = 0;
    for(int i = 0;i<n;++i)
    {
        if(idx <= 1 || nums[i] != nums[idx-1] || nums[i] != nums[idx-2])
            nums[idx++] = nums[i];
    }
    return idx;
}
