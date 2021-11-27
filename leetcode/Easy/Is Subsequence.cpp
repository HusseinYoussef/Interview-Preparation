#include <iostream>

using namespace std;


bool isSubsequence(string s, string t)
{
    int i, j;
    for ( i = 0, j = 0; i < s.size() && j < t.size();)
    {
        if(s[i] == t[j]) 
        {
            ++i, ++j;
            continue;
        }
        else
            ++j;
    }
    return i == s.size();
}
int main()
{
    return 0;
}