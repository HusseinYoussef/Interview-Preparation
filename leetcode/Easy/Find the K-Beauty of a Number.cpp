#include <string>

using namespace std;

int divisorSubstrings(int num, int k)
{
    string s = to_string(num);
    int n = s.size();
    int l = n-1, r = n-1;

    long long exp = 1; int tmp = 0, cnt = 0;
    while(l >= 0)
    {
        if (l < n-k)
        {
            tmp /= 10;
            exp /= 10;
            --r;
        }

        tmp += (s[l] - '0') * exp;
        exp *= 10;

        if (tmp && l <= n-k && num % tmp == 0)
            ++cnt;
        --l;
    }
    return cnt;
}
