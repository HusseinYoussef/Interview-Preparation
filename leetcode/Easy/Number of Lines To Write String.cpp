#include <iostream>
#include <vector>

using namespace std;

vector<int> numberOfLines(vector<int>& widths, string s)
{
    int cnt = 1;
    int width = 0;
    for(int i=0;i<s.size();++i)
    {
        if(widths[s[i]-'a'] + width <= 100)
            width += widths[s[i]-'a'];
        else
            cnt++, width = widths[s[i]-'a'];
    }
    return {cnt, width};
}
