#include <iostream>
#include <stack>

using namespace std;

string minRemoveToMakeValid(string s)
{
    int n = s.size();
    stack<int> st;
    for (int i = 0; i < n;++i)
    {
        if(s[i] == '(')
            st.push(i);
        else if(s[i] == ')')
        {
            if(st.size())
                st.pop();
            else
                s[i] = '#';
        }
    }
    while(!st.empty())
    {
        s[st.top()] = '#';
        st.pop();
    }
    int idx = 0;
    for (int i = 0; i < n;++i)
    {
        if(s[i] == '#')
            continue;
        s[idx++] = s[i];
    }
    return s.substr(0, idx);
}