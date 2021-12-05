#include <iostream>
#include <stack>

using namespace std;

string removeKdigits(string num, int k)
{
    string st = "";
    // prev greater digit
    for (int i = 0; i < num.size(); ++i)
    {
        while(!st.empty() && num[i] < st.back() && k)
            st.pop_back(), --k;

        if(num[i] == '0' && st.empty())
            continue;
        st.push_back(num[i]);
    }
    while(st.size() && k)
        st.pop_back(), --k;
    return st.empty() ? "0" : st;
}

int main()
{
    removeKdigits("9", 1);
    return 0;
}