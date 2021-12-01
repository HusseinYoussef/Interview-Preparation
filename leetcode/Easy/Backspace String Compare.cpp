#include <iostream>
#include <string>

using namespace std;


bool backspaceCompare(string s, string t)
{
    int l = 0, r = 0;
    int i, j;
    for (i = s.size() - 1, j = t.size() - 1; i >= 0 || j >= 0;)
    {
        if(i >= 0 && s[i] == '#')
        {
            ++l;
            --i;
            continue;
        }
        if(j >= 0 && t[j] == '#')
        {
            ++r;
            --j;
            continue;
        }
        if(i >= 0 && s[i] != '#' && l)
        {
            --l;
            --i;
            continue;
        }
        if(j >= 0 && t[j] != '#' && r)
        {
            --r;
            --j;
            continue;
        }
        if(i < 0 || j < 0 || s[i] != t[j])
            return false;
        --i, --j;
    }
    return true;
}

int main()
{
    cout << backspaceCompare("a##c", "#a#c");
    return 0;
}