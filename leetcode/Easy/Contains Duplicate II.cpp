#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    // O(N)
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size();++i)
    {
        if(mp[nums[i]])
        {
            if(i + 1 - mp[nums[i]]<= k)
                return true;
        }
        mp[nums[i]] = i + 1;
    }
    return false;

    // Sliding Window
    // O(n log k)
    
    // set<int> st;
    // for (int i = 0; i < k+1 && i < nums.size();++i)
    // {
    //     int bef = st.size();
    //     st.insert(nums[i]);
    //     if(st.size() == bef)
    //         return true;
    // }
    // for (int i = 0, j = k+1; j < nums.size();++i,++j)
    // {
    //     st.erase(nums[i]);
    //     int bef = st.size();
    //     st.insert(nums[j]);
    //     if(st.size() == bef)
    //         return true;
    // }
    // return false;
}

int main()
{
    vector<int> vec = {1,2,3,1};
    cout << containsNearbyDuplicate(vec, 3);
    return 0;
}