#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string smallestSubsequence(string s)
{
    int n = s.size();
    vector<int> freq(26, 0);
    for(int i = 0;i<n;++i)
        ++freq[s[i]-'a'];
    stack<char>st;
    vector<bool> vis(26, 0);
    for(int i = 0;i<n;++i)
    {
        --freq[s[i]-'a'];
        if(vis[s[i]-'a'])
            continue;
        while(st.size() && s[i] < st.top() && freq[st.top()-'a'] > 0)
        {
            vis[st.top()-'a'] = 0;
            st.pop();
        }
        st.push(s[i]);
        vis[s[i]-'a'] = 1;
    }
    string ans = "";
    while(st.size())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
