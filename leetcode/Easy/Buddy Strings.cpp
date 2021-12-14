#include <iostream>

using namespace std;

bool buddyStrings(string s, string goal)
{
    if(s.size() != goal.size())
        return false;
    int idx1 = -1, idx2 = -1;
    int freq[26];
    memset(freq, 0, sizeof(freq));
    bool f = 0;
    for(int i =0;i<s.size();++i)
    {
        freq[s[i] - 'a']++;
        if(freq[s[i] - 'a'] > 1)
            f = 1;
        if(s[i] != goal[i])
        {
            if(idx1 == -1)
                idx1 = i;
            else if(idx2 == -1)
                idx2 = i;
            else    // strings with > 2 differences
                return false;
        }
    }
    if(idx1 == -1) // same strings
        return f;
    if(idx2 == -1) // strings with 1 difference
        return false;
    return (s[idx1] == goal[idx2]) && (s[idx2] == goal[idx1]);
}
