#include <iostream>
#include <vector>

using namespace std;

 bool isValid(string s)
{
    vector<char> st;
    for(int i=0;i<s.size();++i)
    {
        st.push_back(s[i]);
        if(st.size() >= 3)
        {
            int n = st.size();
            if(st[n-1] == 'c' && st[n-2] == 'b' && st[n-3] == 'a')
            {
                for(int j =0;j<3;++j)
                    st.pop_back();
            }
        }
    }
    return st.empty();
}
