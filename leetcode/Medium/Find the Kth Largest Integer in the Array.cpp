#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(string &a, string &b)
{
    if(a.size() != b.size())
        return a.size() > b.size();
    for (int i = 0; i < a.size();++i)
    {
        if(a[i] != b[i])
            return a[i] > b[i];
    }
    return a[0] < b[0];
}

string kthLargestNumber(vector<string>& nums, int k)
{
    sort(nums.begin(), nums.end(), cmp);
    return nums[k - 1];

    // priority_queue<string, vector<string>, function<bool(string&, string&)>> pq(cmp);
    // for (int i = 0; i < nums.size();++i)
    // {
    //     pq.push(nums[i]);
    //     if(pq.size() > k)
    //         pq.pop();
    // }
    // return pq.top();
}