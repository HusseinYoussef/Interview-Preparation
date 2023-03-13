#include <vector>

using namespace std;

int numberOfSubstrings(string s)
{
    int n = s.size();

    vector<int> freq(3, 0);
    int ans = 0;
    int l = 0, r = 0;
    while(l < n)
    {
        if(freq[0] && freq[1] && freq[2])
        {
            ans += 1 + (n - r);
            --freq[s[l++] - 'a'];
        }
        else if(r < n)
            ++freq[s[r++] - 'a'];
        else
            break;
    }
    return ans;
}
