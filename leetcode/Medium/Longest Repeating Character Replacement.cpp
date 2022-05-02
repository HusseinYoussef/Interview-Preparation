#include <iostream>
#include <vector>

using namespace std;

int mxFreq(vector<int> &freq)
{
    int mx = 0;
    for (int i = 0; i < 26;++i)
        mx = max(mx, freq[i]);
    return mx;
}

int characterReplacement(string s, int k)
{
    int n = s.size();
    vector<int> freq(26, 0);
    int ans = 0;
    int sum = 0, mx = 0;
    for (int i = 0, l = 0; i < n; ++i)
    {
        ++freq[s[i] - 'A'];
        mx = max(mx, freq[s[i] - 'A']);
        if (i-l+1 - mx <= k)
            ans = max(ans, i - l + 1);
        else
            --freq[s[l++] - 'A'];
    }
    return ans;
}