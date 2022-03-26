#include <vector>
#include <climits>

using namespace std;

int nthUglyNumber(int n)
{
    int primes[] = {2, 3, 5};

    vector<int> idx(3, 0);   // the index of the next ugly number to be paired with each prime (partners)
    vector<int> res(n);     // All ugly numbers
    res[0] = 1;
    for (int i = 1; i < n;++i)
    {
        res[i] = INT_MAX;
        // the next ugly number is the smallest among all candidates (since we want them sorted)
        for (int j = 0; j < 3;++j)
        {
            res[i] = min(res[i], primes[j] * res[idx[j]]);
        }
        // for each prime, advance the index of its partner when the min(current ugly number) equals (prime * partner)
        for (int j = 0; j < 3;++j)
        {
            idx[j] += (primes[j] * res[idx[j]]) == res[i];
        }
    }
    return res[n - 1];
}
