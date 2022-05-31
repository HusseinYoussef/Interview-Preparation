#include <iostream>
#include <unordered_map>

using namespace std;

bool hasAllCodes(string s, int k)
{
    int n = s.size();
    unordered_map<int, bool> mp;
    int msk = 0;
    int cnt = 0;
    for (int i = 0; i < n;++i)
    {
        msk |= (s[i] - '0');
        if(i >= k-1)
        {
            msk &= (1 << k) - 1;
            cnt += mp[msk] == 0;
            mp[msk] = 1;
        }
        msk <<= 1;
    }
    return cnt == (1 << k);
}