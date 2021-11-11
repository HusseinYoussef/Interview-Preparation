#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s)
{
    for (int i = 0, j = s.size() - 1; i <= j;)
    {
        if(!isalpha(s[i]) && !isdigit(s[i]))
        {
            ++i;
            continue;
        }
        else if(!isalpha(s[j]) && !isdigit(s[j]))
        {
            --j;
            continue;
        }
        else
        {
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i++, j--;
        }
    }
    return true;
}

int main()
{
    return 0;
}