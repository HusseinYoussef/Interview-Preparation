#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n)
{
    // Sieve
    vector<bool> primes(5000006, 1);
    primes[0] = primes[1] = 0;
    int ans=0;
    for(int i = 2;i*i<n;++i)
    {
        if(primes[i])
        {    
            for(int j = i*i; j<n; j+=i)
                primes[j] = 0;
        }
    }
    for(int i = 2;i<n;++i)
        ans += primes[i];
    return ans;
}
