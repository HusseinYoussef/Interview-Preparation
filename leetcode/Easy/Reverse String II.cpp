#include <iostream>
#include <string>

using namespace std;

string reverseStr(string s, int k)
{
    for (int i = 0; i < s.size(); i+=2*k)
    {
        int l = i, r = min(i + k - 1, (int)s.size() - 1);
        while(l < r)
        {
            swap(s[l], s[r]);
            ++l, --r;
        }
    }
    return s;
}

int main()
{
    reverseStr("abcdefg", 2);
    return 0;
}