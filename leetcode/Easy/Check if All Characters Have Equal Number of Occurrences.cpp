#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

bool allSame(unordered_map<char, int> mp)
{
    set<int> st;
    for (int i = 0;i<26;++i)
    {
        if (mp[i + 'a'] > 0)
            st.insert(mp[i + 'a']);
    }

    return st.size() == 1;
}

bool areOccurrencesEqual(string s)
{
    int n = s.size();

    unordered_map<char, int> mp;

    for (int i = 0;i<n;++i)
        mp[s[i]]++;
    
    for (int i = 0;i<26;++i)
    {
        --mp[i];
        if (allSame(mp))
            return true;
        ++mp[i];
    }

    return false;
}
