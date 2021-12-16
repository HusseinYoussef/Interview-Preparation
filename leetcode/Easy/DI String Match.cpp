#include <iostream>
#include <vector>

using namespace std;

vector<int> diStringMatch(string s)
{
    vector<int> ans;
    int l = 0, r = s.size();
    for (int i = 0; i < s.size();++i)
    {
        if(s[i] == 'I')
            ans.push_back(l++);
        else
            ans.push_back(r--);
    }
    ans.push_back(r);
    return ans;
}