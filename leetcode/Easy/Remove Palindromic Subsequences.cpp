#include <iostream>

using namespace std;

bool checkPalin(string &s)
{
    int l = 0, r = s.size()-1;
    while(l < r)
    {
        if(s[l++] != s[r--])
            return false;
    }
    return true;
}

int removePalindromeSub(string s)
{
    if(checkPalin(s))
        return 1;
    return 2;
}