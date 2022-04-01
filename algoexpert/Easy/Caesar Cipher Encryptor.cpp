#include <iostream>

using namespace std;

string caesarCypherEncryptor(string str, int key)
{
    int n = str.size();
    for (int i = 0; i < n;++i)
        str[i] = (str[i] - 'a' + key) % 26 + 'a';
    return str;
}