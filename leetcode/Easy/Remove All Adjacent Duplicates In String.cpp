#include <iostream>
#include <stack>

using namespace std;

string removeDuplicates(string s)
{
    string st = "";
    for (int i = 0; i < s.size();++i)
    {
        if(!st.empty() && s[i] == st[st.size()-1])
            st.pop_back();
        else
            st.push_back(s[i]);
    }
    return st;
}