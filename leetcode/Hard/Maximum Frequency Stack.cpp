#include <map>
#include <unordered_map>

using namespace std;

class FreqStack {
public:
    unordered_map<int, int>freq;
    map<pair<int, int>, int>mp;
    int idx;
    FreqStack() {
        idx = 0;
    }
    
    void push(int val) {
        ++freq[val];
        mp[{freq[val], idx}] = val;
        ++idx;
    }
    
    int pop() {
        pair<int, int> key = (--mp.end())->first;
        int val = (--mp.end())->second;
        --freq[val];
        mp.erase(key);
        return val;
    }
};
