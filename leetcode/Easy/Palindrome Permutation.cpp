#include <iostream>
#include <cstring>

using namespace std;

bool canPermutePalindrome(string &s)
{
    int freq[30];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < s.size();++i)
    {
        freq[s[i] - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < 30;++i)
        odd += freq[i] & 1;
    return odd <= 1;
}