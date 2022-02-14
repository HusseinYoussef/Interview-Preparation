#include <iostream>

using namespace std;

int maxScore(string s)
{
    int n = s.size();
    int ones = 0;
    for(int i =0;i<n;++i)
        ones += s[i] == '1';

    int ans = 0;
    int o = 0, z = 0;
    for(int i = 0;i<n-1;++i)
    {
        o += s[i] == '1';
        z += s[i] == '0';
        ans = max(ans, z + ones-o);
    }
    return ans;
}
