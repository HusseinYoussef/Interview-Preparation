#include <vector>
#include <set>
#include <deque>

using namespace std;

int longestSubarray(vector<int> &nums, int limit)
{
    // O(NlogN)
    // int n = nums.size();
    // multiset<int> st;
    // int ans = 0;
    // for (int i = 0, l = 0; i < n; ++i)
    // {
    //     st.insert(nums[i]);
    //     if(*st.rbegin() - *st.begin() <= limit)
    //     {
    //         ans = max(ans, (int)st.size());
    //     }
    //     else
    //     {
    //         st.erase(st.find(nums[l++]));
    //     }
    // }
    // return ans;

    // O(N) Monotonic Queue
    int n = nums.size();
    int ans = 0;
    deque<int> maxdq, mindq;
    for (int i = 0, l = 0; i < n;++i)
    {
        while(maxdq.size() && nums[i] >= maxdq.back())
            maxdq.pop_back();
        maxdq.push_back(nums[i]);

        while(mindq.size() && nums[i] <= mindq.back())
            mindq.pop_back();
        mindq.push_back(nums[i]);

        if(maxdq.front() - mindq.front() > limit)
        {
            if(nums[l] == maxdq.front())
                maxdq.pop_front();
            if(nums[l] == mindq.front())
                mindq.pop_front();
            ++l;
        }
        ans = max(ans, i - l + 1);
    }
    return ans;
}