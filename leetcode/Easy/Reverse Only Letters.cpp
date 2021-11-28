#include <iostream>
#include <vector>
#include <string>

using namespace std;


string reverseOnlyLetters(string s)
{
    for (int i = 0, j = s.size() - 1; i < j;)
    {
        if(!isalpha(s[i]))
            ++i;
        if(!isalpha(s[j]))
            --j;
        if(isalpha(s[i]) && isalpha(s[j]))
        {
            swap(s[i], s[j]);
            ++i, --j;
        }
    }
    return s;
}
int main()
{
    return 0;
}