#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s)
{
    int n = s.size();
    int ans = 0;
    vector<int> freq(58, 0);
    int l = 0, r = 0;
    int distinct = 0;
    while(r < n)
    {
        if(distinct + (freq[s[r] - 'A'] == 0) <= 2)
        {
            distinct += (freq[s[r] - 'A'] == 0);
            ++freq[s[r] - 'A'];
            ans = max(ans, r - l + 1);
            ++r;
        }
        else
        {
            --freq[s[l] - 'A'];
            if(freq[s[l] - 'A'] == 0)
                --distinct;
            ++l;
        }
    }
    return ans;
}