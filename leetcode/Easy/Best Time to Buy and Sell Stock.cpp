#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int mx = prices[prices.size() - 1], ans = -INT_MAX;
    for (int i = prices.size()-2; i >= 0;--i)
    {
        ans = max(ans, mx - prices[i]);
        mx = max(mx, prices[i]);
    }
    if(ans < 0)
        return 0;
    return ans;
}

int main()
{

    return 0;
}