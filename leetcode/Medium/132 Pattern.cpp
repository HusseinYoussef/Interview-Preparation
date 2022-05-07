#include <vector>
#include <stack>

using namespace std;

bool find132pattern(vector<int>& nums)
{
    int n = nums.size();

    vector<int> lmin(n);
    stack<int> st;
    int mn = INT_MAX, prevGreater = -1;
    for(int i = 0;i<n;++i)
    {
        lmin[i] = mn;
        mn = min(mn, nums[i]);
        while(st.size() && nums[st.top()] <= nums[i])
            st.pop();
        prevGreater = (st.size())? st.top() : -1;
        st.push(i);

        if(prevGreater != -1 && lmin[prevGreater] < nums[i])
            return true;
    }
    return false;
}
