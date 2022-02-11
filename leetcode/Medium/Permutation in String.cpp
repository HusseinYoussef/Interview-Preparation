#include <vector>

using namespace std;

bool ok(vector<int>&freq1, vector<int>&freq2)
{
    for(int i = 0;i<26;++i)
    {
        if(freq1[i] != freq2[i])
            return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    if(m < n)
        return false;

    vector<int>freq1(26, 0);
    vector<int>freq2(26, 0);
    for(int i = 0;i<n;++i)
    {
        ++freq1[s1[i]-'a'];
        ++freq2[s2[i]-'a'];
    }        
    if(ok(freq1, freq2))
            return true;
    // window size = n
    for(int i = n; i<m;++i)
    {
        ++freq2[s2[i]-'a'];
        --freq2[s2[i-n]-'a'];
        if(ok(freq1, freq2))
            return true;
    }
    return false;
}
