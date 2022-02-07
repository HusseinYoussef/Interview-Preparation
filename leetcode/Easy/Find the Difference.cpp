#include <iostream>
#include <string>
#include <vector>

using namespace std;

char findTheDifference(string s, string t)
{
    vector<int>freq(26, 0);
    for(int i = 0;i<t.size();++i)
    {
        ++freq[t[i]-'a'];
        if(i < s.size())
            --freq[s[i]-'a'];
    }
    for(int i = 0;i<26;++i)
        if(freq[i])
            return i+'a';
    return 0;
}
