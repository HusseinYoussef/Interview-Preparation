#include <iostream>

using namespace std;

int numTilings(int n)
{
    int mod = 1e9 + 7;
    int f[1005];
    int p[1005];
    memset(f, 0, sizeof(f));
    memset(p, 0, sizeof(p));
    f[1] = 1;
    f[2] = 2;
    p[2] = 1;

    for(int i = 3; i<=n; ++i)
    {
        f[i] = ((f[i-1] % mod + f[i-2] % mod) % mod + (2*p[i-1] % mod)) % mod;
        p[i] = (p[i-1] % mod + f[i-2] % mod) % mod;
    }
    return f[n];
}
