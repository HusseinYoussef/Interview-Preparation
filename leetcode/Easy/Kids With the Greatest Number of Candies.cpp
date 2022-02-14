#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
    int n = candies.size();
    vector<bool>ans;
    int mx = 0;
    for(int i = 0;i<n;++i)
        mx = max(mx, candies[i]);
    for(int i = 0;i<n;++i)
        ans.push_back(candies[i]+extraCandies >= mx);
    return ans;
}
