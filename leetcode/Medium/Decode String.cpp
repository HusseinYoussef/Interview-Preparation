#include <iostream>
#include <stack>

using namespace std;

// Recursive
string solve(string &s, int &idx, int digit)
{
    string ans = "";
    string bracket = "";
    int d = 0;
    for (; idx < s.size();++idx)
    {
        if (isalpha(s[idx]))
        {
            bracket += s[idx];
        }
        else if(isdigit(s[idx]))
        {
            d = d * 10 + (s[idx] - '0');
        }
        else if(s[idx] == '[')
        {
            idx += 1;
            bracket += solve(s, idx, d);
            d = 0;
        }
        else if(s[idx] == ']')
        {
            break;
        }
    }
    for (int i = 0; i < digit;++i)
        ans += bracket;

    return ans;
}

string decodeString(string s)
{
    // int idx = 0;
    // return solve(s, idx, 1);

    // Using Stack

    stack<pair<string, int>> st;
    st.push({"", 1});
    int d = 0;
    for (int i = 0; i < s.size();++i)
    {
        if(isalpha(s[i]))
        {
            st.top().first += s[i];
        }
        else if(isdigit(s[i]))
        {
            d = d * 10 + (s[i] - '0');
        }
        else if(s[i] == '[')
        {
            st.push({"", d});
            d = 0;
        }
        else if(s[i] == ']')
        {
            pair<string, int> bracket = st.top();
            st.pop();
            string tmp = "";
            for (int j = 0; j < bracket.second;++j)
                tmp += bracket.first;
            st.top().first += tmp;
        }
    }
    return st.top().first;
}