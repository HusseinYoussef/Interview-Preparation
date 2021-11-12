#include <iostream>
#include <vector>
#include <unordered_map>

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
            mp[i] = 0;
        }
    }
    return ans;
}

int main()
{
    return 0;
}