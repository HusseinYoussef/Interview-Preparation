#include <vector>
#include <map>

using namespace std;

int solve(vector<vector<int> > &A)
{
    int n = A.size();

    // Difference Array method
    map<int, int> mp;
    for (int i = 0; i < n;++i)
    {
        ++mp[A[i][0]];
        --mp[A[i][1]];
    }

    int sum = 0, mx = 1;
    for(auto &p:mp)
    {
        sum += p.second;
        mx = max(mx, sum);
    }
    return mx;
}

