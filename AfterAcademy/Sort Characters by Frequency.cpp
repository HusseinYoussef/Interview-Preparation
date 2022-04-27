#include <iostream>
#include <vector>

using namespace std;

string frequencySort(string s)
{
    int n = s.size();
    vector<int> freq(60, 0);
    vector<int> indices(60, -1);

    for(int i = 0;i<n;++i)
    {
        int idx = s[i]-'A';
        ++freq[idx];
        if(indices[idx] == -1)
            indices[idx] = i;
    }
    
    int idx = 0;
    while(idx < n)
    {
        int mxfreq = 0;
        char c;
        for(int i = 0;i<60;++i)
        {
            if(freq[i] > mxfreq)
            {
                mxfreq = freq[i];
                c = i+'A';
            }
            else if(freq[i] && freq[i] == mxfreq)
            {
                if(indices[i] < indices[c-'A'])
                {
                    c = i+'A';
                }
            }
        }
        
        while(freq[c-'A'])
        {
            s[idx++] = c;
            --freq[c-'A'];
        }
    }
    return s;
}