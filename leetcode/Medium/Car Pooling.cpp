#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    if(a[1] != b[1])
        return a[1] <= b[1];
    return a[2] < b[2];
}

bool carPooling(vector<vector<int>>& trips, int capacity)
{
    // O(N) Difference Array concept
    int arr[1001];
    int n = trips.size();
    memset(arr, 0, sizeof(0));
    for (int i = 0; i < n;++i)
    {
        arr[trips[i][1]] += trips[i][0];
        arr[trips[i][2]] -= trips[i][0];
    }
    int sum = 0;
    for (int i = 0; i <= 1000;++i)
    {
        sum += arr[i];
        if(sum > capacity)
            return false;
    }
    return true;

    // O(N log N)

    // int n = trips.size();
    // sort(trips.begin(), trips.end(), cmp);
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // int cur = 0;
    // for (int i = 0; i < n;++i)
    // {
    //     while(pq.size() && pq.top().first <= trips[i][1])
    //     {
    //         cur -= pq.top().second;
    //         pq.pop();
    //     }
    //     cur += trips[i][0];
    //     if(cur > capacity)
    //         return false;
    //     pq.push({trips[i][2], trips[i][0]});
    // }
    // return true;
}