#include <vector>

using namespace std;

string frequencySort(string s)
{
    int n = s.size();
    vector<int> freq(128, 0);
    for(int i = 0;i<n;++i)
        ++freq[s[i]-'0'];

    int idx = 0;
    while(idx < n)
    {
        char c;
        int mxfreq = 0;
        for(int i= 0;i<128;++i)
        {
            if(freq[i] > mxfreq)
            {
                mxfreq = freq[i];
                c = i+'0';
            }
        }

        while(freq[c-'0'])
        {
            s[idx++] = c;
            --freq[c-'0'];
        }
    }
    return s;
}
