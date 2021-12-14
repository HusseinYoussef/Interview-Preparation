#include <iostream>

using namespace std;

bool primes[35];
void sieve()
{
    for(int i =2;i<35;++i)
        primes[i] = 1;
    primes[0] = primes[1] = 0;
    for(int i =2;i<35;++i)
    {
        for(int j = i*i;j<35;j+=i)
            primes[j] = 0;
    }
}

int countPrimeSetBits(int left, int right)
{
    sieve();
    int ans =0;
    for(int i=left;i<=right;++i)
    {
        int n=i;
        int cnt = 0;
        while(n)
        {
            cnt += n & 1;
            n >>= 1;
        }
        ans += primes[cnt];
    }
    return ans;
}
