#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> hist(m, 0);
    int ans = 0;
    vector<int> l(m, 0);
    vector<int> r(m, 0);
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            if(matrix[i][j] == '0')
                hist[j] = 0;
            else
                ++hist[j];
        }

        stack<int> st;
        for (int j = 0; j < m;++j)
        {
            while(st.size() && hist[st.top()] >= hist[j])
                st.pop();

            l[j] = (st.size()) ? st.top() : -1;
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = m - 1; j >= 0;--j)
        {
            while(st.size() && hist[st.top()] >= hist[j])
                st.pop();
            r[j] = (st.size()) ? st.top() : m;
            st.push(j);
        }

        for (int j = 0; j < m;++j)
        {
            ans = max(ans, hist[j] * (r[j] - l[j] - 1));
        }
    }
    return ans;
}