#include <iostream>
#include <stack>

using namespace std;

int minInsertions(string s)
{
    int n = s.size();
    stack<char> st; 
    int ans = 0;
    for(int i =0 ;i<n;++i)
    {
        if(s[i] == '(')
            st.push(s[i]);
        else if(i+1 < n && s[i+1] == ')')
        {
            // ())
            if(st.size())
                st.pop();
            // ))
            else
                ++ans;
            ++i;
        }
        else
        {
            // () ~ add 1 )
            if(st.size())
            {
                st.pop();
                ++ans;
            }
            // ) ~ add  1 ( and 1 )
            else
                ans += 2;
        }
    }
    return ans + st.size() * 2;
}