#include <vector>
#include <algorithm>

using namespace std;

struct Item { 
   int value, weight; 
};

bool cmp(Item &a, Item &b)
{
    return (a.value * 1.0 / a.weight) > (b.value * 1.0 / b.weight);
}

long fractionalKnapsack(int capacity, vector<Item> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), cmp);

    long ans = 0;
    int idx = 0;
    while(capacity && idx < n)
    {
        int w = min(capacity, arr[idx].weight);

        ans += arr[idx].value * (w * 1.0 / arr[idx].weight);
        
        capacity -= w;
        ++idx;
    }
    return ans;
}