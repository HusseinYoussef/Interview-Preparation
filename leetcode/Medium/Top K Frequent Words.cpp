#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> &a, pair<int, string> &b)
{
    if(a.first != b.first)
        return a.first > b.first;

    return a.second < b.second;
}

vector<string> topKFrequent(vector<string>& words, int k)
{
    int n = words.size();
    unordered_map<string, int> mp;
    for (int i = 0;i<n;++i)
        mp[words[i]]++;

    priority_queue<pair<int, string>, vector<pair<int, string>>,function<bool(pair<int, string> &a, pair<int, string> &b)>> pq(cmp);
    for(auto p : mp)
    {
        pq.push({p.second, p.first});
        if(pq.size() > k)
            pq.pop();
    }
    vector<string> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}