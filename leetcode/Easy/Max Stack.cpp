#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

class MaxStack {

public:
    list<int> dl;
    map<int, vector<list<int>::iterator>> mp;
    MaxStack()
    {
    }

    void push(int number)
    {
        dl.push_back(number);
        mp[number].push_back(--end(dl));
    }

    int pop()
    {
        int val = top();
        dl.pop_back();
        mp[val].pop_back();
        if(mp[val].empty())
            mp.erase(val);
        return val;
    }

    int top()
    {
        return dl.back();
    }
    
    int peekMax()
    {
        return rbegin(mp)->first;
    }
    
    int popMax()
    {
        int val = peekMax();
        auto it = mp[val].back();
        dl.erase(it);
        mp[val].pop_back();
        if(mp[val].empty())
            mp.erase(val);
        return val;
    }
};