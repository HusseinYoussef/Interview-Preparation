#include <iostream>

using namespace std;

int maxPower(string s)
{
    int mx=1;
    int cnt = 1;
    for(int i =1;i<s.size();++i)
    {
        if(s[i] == s[i-1])
            ++cnt;
        else
            cnt = 1;
        mx = max(mx, cnt);
    }
    return mx;   
}
