#include <string>

using namespace std;

string mergeAlternately(string word1, string word2)
{
    int n = word1.size(), m = word2.size();
    string ans = "";
    int l = 0, r = 0;
    while (l < n || r < m)
    {
        if (l < n)
            ans += word1[l++];
        if (r < m)
            ans += word2[r++];
    }
    return ans;
}
