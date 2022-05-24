#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int longestValidParentheses(string s)
{
    int n = s.size();
    stack<int> st;
    vector<int> mxlen(n, 0); // contain max len from i

    // if (anything) then "anything" is valid
    for(int i = 0;i<n;++i)
    {
        if(s[i] == '(')
            st.push(i);
        else if(st.size())
        {
            mxlen[st.top()] = i - st.top() + 1;
            st.pop();
        }
    }

    int ans = 0, len = 0;
    for (int i = 0; i < n;)
    {
        if(mxlen[i] != 0)
        {
            len += mxlen[i];
            ans = max(ans, len);
            i += mxlen[i];
        }
        else
        {
            len = 0;
            ++i;
        }
    }
    return ans;
}