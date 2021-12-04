#include <iostream>
#include <string>
#include <climits>

using namespace std;

int myAtoi(string s)
{
    if(s.empty())
        return 0;

    int i = 0;
    while(s[i] == ' ')
        ++i;

    bool sign = s[i] == '-';

    i += s[i] == '-' || s[i] == '+';
    long long ans = 0;
    bool f = 0;
    while(isdigit(s[i]))
    {
        ans = ans * 10 + (s[i] - '0');
        if(ans > INT_MAX)
            ans = INT_MAX, f = 1;
        ++i;
    }
    return sign? -1 * ans - f: ans;
}
