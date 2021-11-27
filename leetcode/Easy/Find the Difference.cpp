#include <iostream>
#include <string>
#include <vector>

using namespace std;

char findTheDifference(string s, string t)
{
    vector<int> freq(30, 0);
    for (int i = 0; i < s.size();++i)
        freq[s[i] - 'a']++;

    char ans = 'a';
    for (int i = 0; i < t.size();++i)
    {
        if(freq[t[i]-'a'] == 0)
        {
            ans = t[i];
            break;
        }
        --freq[t[i] - 'a'];
    }
    return ans;
}

int main()
{
    return 0;
}