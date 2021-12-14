#include <iostream>
#include <vector>

using namespace std;

vector<int> shortestToChar(string s, char c)
{
    int n = s.size();
    vector<int>ans(n);
    int pre = -1;
    for(int i =0;i<n;++i)
    {
        if(s[i] == c)
            pre = i;
        ans[i] = (pre == -1)? pre : i - pre;
    }
    pre = -1;
    for(int i =n-1;i>=0;--i)
    {
        if(s[i] == c)
            pre = i;
        if(pre != -1)
            ans[i] = (ans[i] == -1)? pre - i: min(ans[i], pre - i);
    }
    return ans;
}
