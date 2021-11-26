#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isAnagram(string s, string t)
{
    if(s.size() != t.size())
        return false;
    vector<int> freq(30, 0);
    for (int i = 0; i < s.size();++i)
    {
        freq[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size();++i)
    {
        freq[t[i] - 'a']--;
    }
    for (int i = 0; i < 30;++i)
    {
        if(freq[i] != 0)
           return false;
    }    
    return true;
}

int main()
{
    return 0;
}