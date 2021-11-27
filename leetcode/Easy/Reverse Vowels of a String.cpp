#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c)
{
    return tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u';
}

string reverseVowels(string s)
{
    for (int i = 0, j = s.size() - 1; i < j;)
    {
        if(!isVowel(s[i]))
        {
            ++i;
        }
        if(!isVowel(s[j]))
        {
            --j;
        }
        if(isVowel(s[i]) && isVowel(s[j]))
        {
            swap(s[i], s[j]);
            ++i, --j;
        }
    }
    return s;
}

int main()
{
    cout << reverseVowels("A man, a plan, a canal: Panama");
    return 0;
}