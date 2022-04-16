#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

int findUnsortedSubarray(vector<int>& nums)
{

    // O(n) Time, O(1) Space
    
    int n = nums.size();
    int mn= INT_MAX, mx = INT_MIN;
    int l = -1, r = -1;
    for (int i = 0, j = n - 1; i < n; ++i, --j)
    {
        if(nums[i] < mx)
            r = i;
        if(nums[j] > mn)
            l = j;
        mx = max(mx, nums[i]);
        mn = min(mn, nums[j]);
    }
    
    if(l == -1)
        return 0;
    return r - l + 1;

    // we need to find for every element, the next smaller element and previous larger element
    // if an element has previous larger or next smaller, then this element in a wrong place
    // find first and last elements that are in wrong places

    // O(n) Monotonic Stack
    int n = nums.size();
    stack<int> st;
    int l = -1, r = -1;
    // find previous larger element
    for (int i = 0; i < n; ++i)
    {
        while (st.size() && nums[st.top()] <= nums[i])
            st.pop();
        if (st.size())
            r = i;
        st.push(i);
    }
    while (st.size())
        st.pop();

    // find next smaller element
    for (int i = n - 1; i >= 0;--i)
    {
        while(st.size() && nums[st.top()] >= nums[i])
            st.pop();
        if(st.size())
            l = i;
        st.push(i);
    }

    if (l == -1)
        return 0;
    return r - l + 1;


    // O(nlogn) Time, O(n) Space

    int n = nums.size();
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    int l = -1, r = -1;
    for(int i = 0;i<n;++i)
    {
        if(tmp[i] != nums[i])
        {
            if(l == -1)
                l = i;
            r = i;
        }
    }
    if(l == -1)
        return 0;
    return r - l + 1;
}