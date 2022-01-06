#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int>& nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    return nums[n-k];

    // priority_queue<int, vector<int>, greater<int>> pq;
    // for (int i = 0; i < nums.size();++i)
    // {
    //     pq.push(nums[i]);
    //     if(pq.size() > k)
    //         pq.pop();
    // }
    // return pq.top();
}