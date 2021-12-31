#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens)
{
    int n = tokens.size();
    stack<int> st;
    int num = 0;
    for(int i =0;i<n;++i)
    {
        if(tokens[i].size() == 1 && !isdigit(tokens[i][0]))
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            int res;
            if(tokens[i][0] == '+')
                res = op1 + op2;
            else if(tokens[i][0] == '-')
                res = op1 - op2;
            else if(tokens[i][0] == '*')
                res = op1 * op2;
            else
                res = op1 / op2;
            st.push(res);
        }
        else
        {
            st.push(stoi(tokens[i]));
        }
    }
    return st.top();
}
