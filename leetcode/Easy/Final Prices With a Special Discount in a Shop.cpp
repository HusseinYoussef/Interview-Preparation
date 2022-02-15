#include <vector>
#include <stack>

using namespace std;

vector<int> finalPrices(vector<int>& prices)
{
    int n = prices.size();
    stack<int> st;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0;--i)
    {
        while(st.size() && st.top() > prices[i])
            st.pop();
        ans[i] = (st.size()) ? prices[i] - st.top() : prices[i];
        st.push(prices[i]);
    }
    return ans;
}