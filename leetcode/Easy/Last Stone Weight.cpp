#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones)
{
    int n = stones.size();
    priority_queue<int> pq;
    for (int i = 0; i < n;++i)
        pq.push(stones[i]);

    int s1, s2;
    while(pq.size() > 1)
    {
        s1 = pq.top();
        pq.pop();
        s2 = pq.top();
        pq.pop();
        if(s1 != s2)
            pq.push(s1 - s2);
    }
    if(!pq.empty())
        return pq.top();
    return 0;
}