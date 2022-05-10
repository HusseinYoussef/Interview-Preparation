#include <iostream>
#include <vector>

using namespace std;

string minWindow(string s, string t)
{
    int n = s.size(), m = t.size();
    int matches = 60;
    vector<int> freqt(60, 0);
    for (int i = 0; i < m;++i)
    {
        ++freqt[t[i] - 'A'];
        if(freqt[t[i] - 'A'] == 1)
            --matches;
    }

    vector<int> freqs(60, 0);
    int start = -1, len = n + 1;
    int i = 0, j = 0;
    while(i <= j)
    {
        // all match (length of freq array)
        if(matches == 60)
        {
            if(j-i < len)
            {
                start = i;
                len = j - i;
            }
            int idx = s[i] - 'A';
            --freqs[idx];
            // we removed one match
            if(freqs[idx] == freqt[idx] - 1)
                --matches;
            ++i;
        }
        else if(j < n)
        {
            int idx = s[j] - 'A';
            ++freqs[idx];
            // got a new match
            if(freqs[idx] == freqt[idx])
                ++matches;
            ++j;
        }
        else
            break;
    }
    if(start == -1)
        return "";
    return s.substr(start, len);
}