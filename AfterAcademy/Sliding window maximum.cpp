#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    int n = nums.size();
    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < n;++i)
    {
        // remove elments out of window bounds
        while(q.size() && q.front() <= i-k)
            q.pop_front();

        // remove smaller elements (just like monotonic stack to get previous larger element)
        while(q.size() && nums[i] >= nums[q.back()])
            q.pop_back();
        q.push_back(i);
        
        if(i>=k-1)
            ans.push_back(nums[q.front()]);
    }
    return ans;
}