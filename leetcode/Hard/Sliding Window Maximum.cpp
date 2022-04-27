#include <vector>
#include <set>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    // O(NlogK)
    int n = nums.size();
    multiset<int> st;
    vector<int> ans;
    for (int i = 0; i < n;++i)
    {
        st.insert(nums[i]);
        if(i >= k)
            st.erase(st.find(nums[i-k]));

        if(st.size() == k)
            ans.push_back(*(--st.end()));
    }
    return ans;

    // O(N) ~ Monotonic Queue
    int n = nums.size();
    vector<int> ans;
    // a queue to store elements in decreasing order (q.front is the max)
    deque<int> q;
    for (int i = 0; i < n;++i)
    {
        // remove elments out of window bounds
        while(q.size() && q.front() <= i-k)
            q.pop_front();

        // remove smaller elements ~ (just like monotonic stack to get previous larger element)
        while(q.size() && nums[i] >= nums[q.back()])
            q.pop_back();
        q.push_back(i);

        if(i>=k-1)
            ans.push_back(nums[q.front()]);
    }
    return ans;
}