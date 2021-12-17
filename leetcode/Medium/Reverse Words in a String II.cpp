#include <iostream>
#include <string>

using namespace std;

void reverse(string &s, int i, int j)
{
    while(i < j)
    {
        swap(s[i++], s[j--]);
    }
}

string reverseWords(string s)
{
   // reverse each word then reverse the whole string => every word will be just in place
    for (int i = -1, j = 0; j < s.size(); ++j)
    {
        if (s[j] != ' ' && (j == 0 || s[j - 1] == ' '))
        {
            i = j;
        }
        if ((j+1 == s.size() || s[j+1] == ' ') && i != -1)
        {
            reverse(s, i, j);
            i = -1;
        }
    }
    reverse(s, 0, s.size() - 1);    
    return s;
}