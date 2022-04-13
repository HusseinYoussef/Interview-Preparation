#include <iostream>
#include <vector>

using namespace std;

int findRank(string A)
{
    int n = A.size();
    vector<bool> c(130, 0);

    int ans = 0, mod = 1000003;
    int fact[120];
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 120;++i)
        fact[i] = (i * (fact[i - 1] % mod)) % mod;

    // O(26n)
    for (int i = n - 1; i >= 0; --i)
    {
        int idx = A[i] - 'A';
        // number of chars smaller than current char
        int cnt = 0;
        for (int j = 0; j < idx; ++j)
            cnt += c[j];

        ans += ((cnt % mod) * (fact[n - i - 1])) % mod;
        ans %= mod;
        c[idx] = 1;
    }
    return ans+1;
}