#include <iostream>
#include <vector>

using namespace std;

string reformat(string s)
{
    vector<char> c, d;
    for (int i = 0; i < s.size();++i)
    {
        if(isalpha(s[i]))
            c.push_back(s[i]);
        else
            d.push_back(s[i]);
    }
    if(abs((int)c.size() - (int)d.size()) > 1)
        return "";
    
    bool f = c.size() > d.size();
    int l = 0, r = 0;
    for (int i = 0; i < s.size();++i)
    {
        if(f)
            s[i] = c[l++];
        else
            s[i] = d[r++];
        f = !f;
    }
    return s;
}