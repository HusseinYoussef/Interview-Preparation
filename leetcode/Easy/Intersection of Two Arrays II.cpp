#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, int> mp;
    vector<int> ans;
    for(int i:nums1)
    {
        mp[i]++;
    }
    for(int i:nums2)
    {
        if(mp[i])
        {
            ans.push_back(i);
            mp[i]--;
        }
    }
    return ans;

    // Interview Question (O(N) Time and O(1) Space, Assume arrays are sorted)
    
    // vector<int> ans;
    // sort(nums1.begin(), nums1.end());
    // sort(nums2.begin(), nums2.end());
    // int l = 0, r = 0;
    // while(l < nums1.size() && r < nums2.size())
    // {
    //     if(nums1[l] == nums2[r])
    //     {
    //         ans.push_back(nums1[l]);
    //         ++l, ++r;
    //     }
    //     else
    //     {
    //         if(nums1[l] < nums2[r])
    //             ++l;
    //         else
    //             ++r;
    //     }
    // }
    // return ans;
}

int main()
{
    return 0;
}