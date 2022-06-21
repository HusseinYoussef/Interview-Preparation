#include <vector>
#include <queue>

using namespace std;

int minSetSize(vector<int>& arr)
{
    int n = arr.size();

    vector<int> freq(100005, 0);
    for (int i = 0; i < n;++i)
        ++freq[arr[i]];

    priority_queue<int> pq;
    for (int i = 0; i < 100005;++i)
    {
        if(freq[i])
            pq.push(freq[i]);
    }

    int ans = 0;
    while (!pq.empty())
    {
        n -= pq.top();
        ++ans;
        pq.pop();
        if(n <= arr.size() / 2)
            break;
    }
    return ans;
}