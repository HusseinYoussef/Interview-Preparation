#include <iostream>
#include <stack>

using namespace std;

int scoreOfParentheses(string s)
{
    int n = s.size();
    stack<int>st;
    int ans = 0;
    for(int i = 0;i<n;++i)
    {
        if(s[i] == '(')
            st.push(0);
        else
        {
            int val = st.top();
            st.pop();
            if(val == 0)
                val = 1;
            else
                val *= 2;
            if(st.empty())
                ans += val;
            else
                st.top() += val;
        }

    }
    return ans;
}
