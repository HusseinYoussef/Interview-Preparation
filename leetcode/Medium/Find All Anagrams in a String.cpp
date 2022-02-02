#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> &wfreq, vector<int> &pfreq)
{
    for (int i = 0; i <= 26;++i)
    {
        if(wfreq[i] != pfreq[i])
            return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p)
{
    if(p.size() > s.size())
        return {};

    vector<int> pfreq(27, 0);
    vector<int> wfreq(27, 0);
    int wsize = p.size();
    for (int i = 0; i < wsize;++i)
        ++pfreq[p[i] - 'a'];

    int i;
    for (i = 0; i < wsize;++i)
        ++wfreq[s[i] - 'a'];

    vector<int> ans;
    for (i = wsize; i < s.size();++i)
    {
        if(check(wfreq, pfreq))
            ans.push_back(i - wsize);
        wfreq[s[i] - 'a']++;
        wfreq[s[i - wsize] - 'a']--;
    }
    if(check(wfreq, pfreq))
        ans.push_back(i - wsize);
    return ans;
}