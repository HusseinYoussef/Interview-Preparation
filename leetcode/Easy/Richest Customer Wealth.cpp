#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts)
{
    int n = accounts.size(), m = accounts[0].size();
    int ans = 0, sum = 0;
    for (int i = 0; i < n;++i)
    {
        sum = 0;
        for (int j = 0; j < m;++j)
            sum += accounts[i][j];
        ans = max(ans, sum);
    }
    return ans;
}