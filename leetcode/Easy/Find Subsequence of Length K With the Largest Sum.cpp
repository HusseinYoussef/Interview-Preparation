#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
vector<int> maxSubsequence(vector<int>& nums, int k)
{
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < nums.size();++i)
    {
        pq.push({nums[i], i});
        if(pq.size() > k)
            pq.pop();
    }
    vector<pair<int, int>> vec;
    while(!pq.empty())
    {
        vec.push_back(pq.top());
        pq.pop();
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < vec.size();++i)
        ans.push_back(vec[i].first);
    return ans;
}