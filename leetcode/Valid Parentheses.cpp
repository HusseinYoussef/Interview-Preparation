#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for(char c : s)
    {
        if(c == '{' || c == '[' || c == '(')
            st.push(c);
        else
        {
            if (st.size())
            {
                if(c == '}' && st.top() == '{' || c == ']' && st.top() == '[' || c == ')' && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }
    return !st.size();
}
int main()
{
    cout << isValid("([)]");
    return 0;
}