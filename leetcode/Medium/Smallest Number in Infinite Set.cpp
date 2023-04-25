#include <queue>

using namespace std;

class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    bool freq[1005];
    int cur;
    SmallestInfiniteSet()
    {
        cur = 1;
        for(int i = 0;i<=1000;++i)
            freq[i] = 1;
    }
    
    int popSmallest()
    {
        int val = cur;
        if (!pq.empty() && pq.top() < cur)
        {
            val = pq.top();
            pq.pop();
        }
        else
            ++cur;

        freq[val] = 0;
        return val;
    }
    
    void addBack(int num)
    {
        if (freq[num])
            return;
        
        freq[num] = 1;
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
