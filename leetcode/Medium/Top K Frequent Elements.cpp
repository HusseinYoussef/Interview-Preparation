#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    // O(N log K)
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size();++i)
        mp[nums[i]]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(pair<int, int> p : mp)
    {
        pq.push({p.second, p.first});
        if(pq.size() > k)
            pq.pop();
    }
    while(!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;

    // O(N)

    // vector<vector<int>>freq(nums.size()+1);
    // unordered_map<int, int> mp;
    // vector<int> ans;
    // for (int i = 0; i < nums.size();++i)
    //     mp[nums[i]]++;
    // for(pair<int, int> p : mp)
    // {
    //     freq[p.second].push_back(p.first);
    // }

    // for (int i = nums.size(); i > 0;--i)
    // {
    //     if(freq[i].size())
    //     {
    //         for (int j = 0; j < freq[i].size();++j)
    //         {
    //             ans.push_back(freq[i][j]);
    //             if(ans.size() == k)
    //                 return ans;
    //         }
    //     }
    // }
    // return ans;
}