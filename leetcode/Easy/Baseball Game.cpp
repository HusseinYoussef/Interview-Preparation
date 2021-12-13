#include <iostream>
#include <vector>

using namespace std;

int calPoints(vector<string>& ops)
{
    vector<int>st;
    int ans =0;
    for(int i =0;i<ops.size();++i)
    {
        int last = st.size();
        if(ops[i] == "+")
        {
            int val = st[last-1] + st[last-2];
            st.push_back(val);
            ans += val;
        }
        else if(ops[i] == "D")
        {
            int val = 2*st[last-1];
            st.push_back(val);
            ans += val;
        }
        else if(ops[i] == "C")
            ans-= st[last-1], st.pop_back();
        else
        {
            int val = stoi(ops[i]);
            st.push_back(val);
            ans += val;
        }
    }
    return ans;
}
