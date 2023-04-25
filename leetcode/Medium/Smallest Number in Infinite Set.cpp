class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    bool freq[1005];
    SmallestInfiniteSet()
    {
        for(int i = 1;i<=1000;++i)
        {
            freq[i] = 1;
            pq.push(i);
        }
    }
    
    int popSmallest()
    {
        int val = pq.top();
        freq[val] = 0;
        pq.pop();
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
