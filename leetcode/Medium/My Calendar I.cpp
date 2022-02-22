#include <vector>

using namespace std;

class MyCalendar {
public:
    vector<pair<int, int>> vec;
    MyCalendar()
    {}
    
    bool book(int start, int end)
    {
        for (int i = 0; i < vec.size();++i)
        {
            if((start >= vec[i].first && start < vec[i].second) || (end > vec[i].first && end <= vec[i].second) || (start <= vec[i].first && end >= vec[i].second))
                return false;
        }
        vec.push_back({start, end});
        return true;
    }
};