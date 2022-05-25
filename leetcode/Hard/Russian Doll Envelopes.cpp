#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    if(a[0] != b[0])
        return a[0] < b[0];
    return b[1] < a[1];
}

int maxEnvelopes(vector<vector<int>>& envelopes)
{
    int n = envelopes.size();
    // sort asc in width, and desc in height if width is the same
    sort(envelopes.begin(), envelopes.end(), cmp);
 
    // LIS in nlogn using Binary Search
    set<int> st;
    for (int i = 0; i < n;++i)
    {
        // first elem > current
        auto elem = st.lower_bound(envelopes[i][1]);
        if(elem != st.end())
            st.erase(elem);
        st.insert(envelopes[i][1]);
    }
    return st.size();
}