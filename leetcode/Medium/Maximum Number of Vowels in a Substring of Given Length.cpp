#include <string>

using namespace std;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(string s, int k)
{
    int n = s.size();
    int l = 0, r = 0;
    int cnt = 0;
    int ans = 0;
    while(r < n)
    {
        if(r >= k)
            cnt -= isVowel(s[l++]);

        cnt += isVowel(s[r]);

        if (r >= k-1)
            ans = max(ans, cnt);
        ++r;
    }
    return ans;
}
