#include <iostream>
#include <vector>

using namespace std;

string removeDuplicates(string s, int k)
{
    int n = s.size();
    vector<pair<char, int>> st;
    int cnt = 0;
    for(int i=0;i<n;++i)
    {
        if(st.size() && s[i] == st.back().first)
            ++st.back().second;
        else
            st.push_back({s[i], 1});

        if(st.size() && st.back().second == k)
            st.pop_back();
    }
    s.clear();
    for(int i = 0;i <st.size();++i)
    {
        for(int j = 0;j<st[i].second;++j)
            s += st[i].first;
    }
    return s;
}
