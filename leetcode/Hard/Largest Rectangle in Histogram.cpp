#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();
    vector<int> l(n);
    stack<int> st;
    for (int i = 0; i < n;++i)
    {
        while(st.size() && heights[st.top()] >= heights[i])
            st.pop();
        l[i] = (st.size()) ? st.top() : -1;
        st.push(i);
    }
    while(st.size())
        st.pop();
    int mx = 0;
    for (int i = n - 1; i >= 0;--i)
    {
        while(st.size() && heights[st.top()] >= heights[i])
            st.pop();
        int r = (st.size()) ? st.top() : n;
        // width = left width + right width - 1 (since i is included twice)
        int area = ((i - l[i]) + (r - i) - 1) * heights[i];
        mx = max(mx, area);
        st.push(i);
    }
    return mx;
}