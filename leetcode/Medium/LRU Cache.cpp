#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    int sz;
    list<pair<int, int>> dl;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    
    LRUCache(int capacity)
    {
        sz = capacity;
    }
    
    int get(int key)
    {
        if(mp.find(key) == mp.end())
            return -1;

        int val = mp[key]->second;
        dl.erase(mp[key]);
        dl.push_front({key, val});
        mp[key] = dl.begin();
        return val;
    }
    
    void put(int key, int value)
    {
        if(mp.find(key) != mp.end())
        {
            dl.erase(mp[key]);
            dl.push_front({key, value});
            mp[key] = dl.begin();
        }
        else
        {
            if(sz)
            {
                dl.push_front({key, value});
                mp[key] = dl.begin();
                --sz;
            }
            else
            {
                int LRU_Key = dl.back().first;
                dl.erase(mp[LRU_Key]);
                mp.erase(LRU_Key);
                dl.push_front({key, value});
                mp[key] = dl.begin();
            }
        }
    }
};