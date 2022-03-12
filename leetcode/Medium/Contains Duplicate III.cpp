#include <vector>
#include <set>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    multiset<long long> st;
    int n = nums.size();
    for (int i = 0; i < n;++i)
    {
        long long l = nums[i] - t, r = nums[i] + t;
        auto it = st.lower_bound(l);
        if(it != st.end() && *it <= r)
            return true;
        st.insert(nums[i]);
        if(i >= k)
            st.erase(st.find(nums[i - k]));
    }
    return false;
}