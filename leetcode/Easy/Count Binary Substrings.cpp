#include <iostream>

using namespace std;

int countBinarySubstrings(string s)
{
    int ans = 0;
    int pre = -1, cnt = 0;
    char state = s[0];
    for(int i =0;i<s.size();++i)
    {
        if(s[i] == state)
            ++cnt;
        else if(s[i] != state)
        {
            if(pre != -1)
                ans += min(pre, cnt);
            pre = cnt;
            state = s[i];
            cnt = 1;
        }
    }
    if(pre != -1)
        ans += min(pre, cnt);
    return ans;
}
