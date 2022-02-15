#include <vector>
#include <unordered_map>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0;i<n;++i)
        pq.push(arr[i]);

    int rank = 1;
    while(!pq.empty())
    {
        if(mp[pq.top()] == 0)
            mp[pq.top()] = rank++;
        pq.pop();
    }
    for(int i = 0;i<n;++i)
        arr[i] = mp[arr[i]];
    return arr;
}
