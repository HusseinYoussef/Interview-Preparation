#include <iostream>

using namespace std;

bool isOneEditDistance(string s, string t)
{
    if(s.size() == t.size())
    {
        bool change = 0;
        for (int i = 0; i < s.size();++i)
        {
            if(s[i] != t[i])
            {
                if(change)
                    return false;
                change = 1;
            }
        }
        return change;
    }
    else if(abs((int)s.size() - (int)t.size()) == 1)
    {
        bool change = 0;
        if(t.size() < s.size())
            swap(s, t);
        // s is smaller, t is bigger
        for (int i = 0, j = 0; i < s.size();)
        {
            if(s[i] != t[j])
            {
                if(change)
                    return false;
                change = true;
            }
            else
                ++i;
            ++j;
        }
        return true;
    }
    return false;
}