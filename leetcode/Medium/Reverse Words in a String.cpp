#include <iostream>
#include <string>
#include <vector>

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
    int idx = 0;
    // remove redundent spaces
    for (int i = 0; i < s.size();++i)
    {
        if(s[i] != ' ' && idx != 0 && s[i-1] == ' ')
        {
            s[idx++] = ' ';
        }
        if(s[i] != ' ')
        {
            s[idx++] = s[i];
        }
    }
    s.resize(idx);
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
int main()
{
    string s = "  hello   world  ";
    reverseWords(s);
    return 0;
}