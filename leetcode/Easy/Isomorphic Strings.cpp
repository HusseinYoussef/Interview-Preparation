#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> mp1, mp2;
    for (int i = 0; i < s.size();++i)
    {
        if(!mp1[s[i]] && !mp2[t[i]])
        {
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        else
        {
            if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i])
                return false;
        }
    }
    return true;
}

int main()
{
    cout << isIsomorphic("paper", "title");
    return 0;
}