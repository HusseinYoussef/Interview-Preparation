#include <vector>
#include <unordered_map>

using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() 
    {}
    
    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp)
    {
        int l = -1, r = mp[key].size(), mid;
        while (r - l > 1)
        {
            mid = l + (r - l) / 2;
            if (mp[key][mid].second <= timestamp)
                l = mid;
            else
                r = mid;
        }
        return (l >= 0) ? mp[key][l].first : "";
    }
};
