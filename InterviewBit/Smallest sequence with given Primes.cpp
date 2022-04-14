#include <vector>
#include <climits>

using namespace std;

vector<int> solve(int A, int B, int C, int D)
{
    vector<int> primes = {A, B, C};
    // for each prime, index of the next ugly number to be paired with
    vector<int> indices(3, 0);
    vector<int> res(D + 1);
    vector<int> ans;
    res[0] = 1;
    for (int i = 1; i <= D;++i)
    {
        int mn = INT_MAX;
        for (int i = 0; i < 3;++i)
        {
            mn = min(mn, primes[i] * res[indices[i]]);
        }

        for (int i = 0; i < 3;++i)
        {
            if(primes[i] * res[indices[i]] == mn)
                ++indices[i];
        }
        ans.push_back(mn);
        res[i] = mn;
    }
    return ans;
}