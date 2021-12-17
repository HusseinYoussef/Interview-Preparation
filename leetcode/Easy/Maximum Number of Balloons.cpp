#include <iostream>
#include <cstring>

using namespace std;

int maxNumberOfBalloons(string text)
{
    int arr[26];
    string s = "balloon";
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < text.size();++i)
        arr[text[i] - 'a']++;
    int mn = 10005;
    for (int i = 0; i < s.size();++i)
    {
        if(s[i] == 'l' || s[i] == 'o')
            mn = min(mn, arr[s[i] - 'a'] / 2);
        else
            mn = min(mn, arr[s[i] - 'a']);
    }
    return mn;
}