#include <vector>
#include <queue>

using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes)
{
    int p = primes.size();

    // {ugly_number, prime_idx}
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
    for (int i = 0; i < p;++i)
        pq.push({primes[i], i});

    // for each prime, the index of the next ugly number to be paired with (partner idx)
    vector<int> indices(p, 0);
    vector<int> res(n);
    res[0] = 1;
    int prime_idx = 0;
    for (int i = 1; i < n;++i)
    {
        // the next ugly number will be at top (min number)
        res[i] = pq.top().first;

        // Advance the index of partners for primes that result in those ugly numbers that equal current ugly number (min)
        while(pq.size() && pq.top().first == res[i])
        {
            prime_idx = pq.top().second;
            pq.pop();
            ++indices[prime_idx];
            pq.push({(long)primes[prime_idx] * res[indices[prime_idx]], prime_idx});
        }
    }
    return res[n - 1];
}