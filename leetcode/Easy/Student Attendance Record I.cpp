#include <iostream>
#include <vector>

using namespace std;

bool checkRecord(string s)
{
    int l = 0, mx = 0;
    int a = 0;
    for (int i = 0; i < s.size();++i)
    {
        a += s[i] == 'A';
        l = s[i] == 'L' ? l + 1 : 0;
        mx = max(mx, l);
    }
    return a < 2 && mx < 3;
}