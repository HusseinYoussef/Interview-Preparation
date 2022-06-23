#include <vector>
#include <queue>
using namespace std;

vector<int> sortKSortedArray(vector<int> array, int k)
{
    int n = array.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    int idx = 0;
    for(int i = 0;i<n;++i)
    {
        pq.push(array[i]);

        if(pq.size() == k+1)
        {
            array[idx++] = pq.top();
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        array[idx++] = pq.top();
        pq.pop();
    }
    return array;
}