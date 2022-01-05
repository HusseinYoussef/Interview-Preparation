#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int eatenApples(vector<int>& apples, vector<int>& days)
{
    int n = days.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int ans = 0, i;
    for(i =0;i<n;++i)
    {
        while(pq.size() && pq.top().first <= i) 
            pq.pop();
        if(days[i])
            pq.push({i+days[i], apples[i]});
        if(pq.size())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            if(p.second > 1)
                pq.push({p.first, p.second-1});
            ++ans;
        }
    }
    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        if(p.first <= i)
            continue;
        int delta = min(p.first-i, p.second);
        ans += delta;
        i += delta;
    }
    return ans;
}
