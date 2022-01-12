#include <iostream>
#include <vector>

using namespace std;

int n;
int getNext(vector<int>& nums, int idx)
{
    return ((idx + nums[idx]) % n + n) % n;
}

bool circularArrayLoop(vector<int>& nums)
{
    n = nums.size();
    for (int i = 0; i < n;++i)
    {
        if(nums[i] == 0)
            continue;

        int walker = i, runner = getNext(nums, walker);
        while(walker != runner && nums[i] * nums[runner] > 0 && nums[i] * nums[getNext(nums, runner)] > 0)
        {
            walker = getNext(nums, walker);
            runner = getNext(nums, getNext(nums, runner));
        }
        // not one element loop
        if(walker == runner && walker != getNext(nums, walker))
        {
            return true;
        }

        // signs differed
        // set elements to 0 just before the sign change
        walker = i;
        int val = nums[i];
        while(val * nums[walker] > 0)
        {
            int nxt = getNext(nums, walker);
            nums[walker] = 0;
            walker = nxt;
        }
    }
    return false;
}