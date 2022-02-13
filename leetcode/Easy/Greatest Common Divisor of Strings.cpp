#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

string gcdOfStrings(string str1, string str2)
{
    int s1 = str1.size(), s2 = str2.size();
    if(str1+str2 != str2+str1)
        return "";
    return str1.substr(0, gcd(max(s1, s2), min(s1,s2)));
}
