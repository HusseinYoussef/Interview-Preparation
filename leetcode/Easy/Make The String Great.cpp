#include <iostream>

using namespace std;

string makeGood(string s)
{
    int n = s.size();
    string ans = "";
    for (int i = 0; i < n;++i)
    {
        if(ans.size() && (isupper(ans.back()) || isupper(s[i])) && (islower(ans.back()) || islower(s[i])) && tolower(ans.back()) == tolower(s[i]))
            ans.pop_back();
        else
            ans.push_back(s[i]);
    }
    return ans;
}