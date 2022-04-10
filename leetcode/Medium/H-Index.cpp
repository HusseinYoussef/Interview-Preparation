#include <vector>

using namespace std;

int hIndex(vector<int>& citations)
{
    int n = citations.size();
    vector<int> freq(1005, 0);
    for(int i = 0;i<n;++i)
        ++freq[citations[i]];

    int idx = 0;
    for(int i = 0;i<=1000;++i)
    {
        while(freq[i])
        {
            citations[idx++] = i;
            --freq[i];
        }
    }

    for(int h = n;h>0;--h)
    {
        if(citations[n-h] >= h && (h==n || citations[n-h-1] <= h))
            return h;
    }
    return 0;
}
