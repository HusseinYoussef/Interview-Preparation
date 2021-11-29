#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool repeatedSubstringPattern(string s)
{
    bool freq[30];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < s.size();++i)
        freq[s[i] - 'a'] = 1;
    int cnt = 0;
    for (int i= 0; i < 30;++i)
        cnt += freq[i];
    if(cnt == 1 && s.size() > 1)
        return true;

    for (int i = 2; i < s.size();++i)
    {
        if(s.size() % i == 0)
        {
            string sub = s.substr(0, s.size() / i);
            bool f = true;
            for (int k = sub.size(); k < s.size();k+=sub.size())
            {
                if(s.substr(k, sub.size()) != sub)
                {
                    f = false;
                    break;
                }
            }
            if(f)
                return true;
        }
    }
    return false;
}

int main()
{
    string s = "abcabcabc";
    repeatedSubstringPattern(s);
    return 0;
}