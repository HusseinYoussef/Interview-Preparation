#include <iostream>
#include <vector>

using namespace std;

class RecentCounter
{
public:
    vector<int> vec;
    int idx;
    int cnt;
    RecentCounter()
    {
        idx = 0;
    }
    
    int ping(int t)
    {
        vec.push_back(t);
        while(t-vec[idx] > 3000)
            ++idx;
        return vec.size() - idx;
    }
};