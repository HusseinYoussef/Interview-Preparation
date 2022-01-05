#include <iostream>

using namespace std;

int balancedStringSplit(string s)
{
    int r = 0, l = 0, ans = 0;
    for(int i =0;i<s.size();++i)
    {
        r += s[i] == 'R';
        l += s[i] == 'L';
        if(r == l)
        {
            ans++;
            r = l = 0;
        }
    }
    return ans;
}
