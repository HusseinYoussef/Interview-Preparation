#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    // vector<int> arr(101, 0);
    // vector<int> ans(temperatures.size());
    // for (int i = temperatures.size() - 1; i >= 0;--i)
    // {
    //     int mn = temperatures.size();
    //     for (int j = temperatures[i] + 1; j <= 100;++j)
    //     {
    //         if(arr[j])
    //             mn = min(mn, arr[j]);
    //     }
    //     ans[i] = mn == temperatures.size() ? 0 : mn - i;
    //     arr[temperatures[i]] = i;
    // }
    // return ans;

    // Monotonic Stack (O(N)) => Looking for next greater element
    vector<int> ans(temperatures.size(), 0);
    stack<int> st;
    for (int i = temperatures.size() - 1; i >= 0;--i)
    {
        while(st.size() && temperatures[i] >= temperatures[st.top()])
        {
            st.pop();
        }
        if(st.size())
            ans[i] = st.top() - i;
        st.push(i);
    }

    // Monotonic Stack (O(N)) => Looking for previous greater element
    // for (int i = 0; i < temperatures.size();++i)
    // {
    //     while(st.size() && temperatures[i] > temperatures[st.top()])
    //     {
    //         ans[st.top()] = i - st.top();
    //         st.pop();
    //     }
    //     st.push(i);
    // }
    return ans;
}

int main()
{
    vector<int> vec = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(vec);
    for(int i:ans)
        cout << i;
    return 0;
}