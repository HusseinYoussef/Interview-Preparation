#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(string s, int l, int r)
{
    for (int i = l, j = r; i < j;)
    {
        if(s[i] != s[j])
            return false;
        ++i, --j;
    }
    return true;
}

bool validPalindrome(string s)
{
    for (int i = 0, j = s.size() - 1; i < j;)
    {
        if(s[i] != s[j])
            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        ++i, --j;
    }
    return true;
}

int main()
{
    return 0;
}