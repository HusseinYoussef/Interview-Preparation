#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minDeletions(string s)
{
    int n = s.size();
    vector<int> freq(26, 0);
    for (int i = 0; i < n;++i)
        ++freq[s[i] - 'a'];

    priority_queue<int> pq;
    for (int i = 0; i < 26;++i)
    {
        if(freq[i])
            pq.push(freq[i]);
    }
    int ans = 0, maxFreq = n; // max valid freq
    while(!pq.empty())
    {
        int f = pq.top();
        pq.pop();
        // freq = maxfreq
        if(maxFreq < f)
        {
            ans += f - maxFreq;
            maxFreq = max(0, maxFreq - 1);
        }
        else
            maxFreq = max(0, f - 1);
    }
    return ans;
}