#include <set>

using namespace std;

class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar()
    {}
    
    bool book(int start, int end)
    {
        auto nxt = st.lower_bound({start, end});
        if(nxt != st.end() && nxt->first < end)
            return false;
        if (nxt != st.begin() && start < (--nxt)->second)
            return false;
        st.insert({start, end});
        return true;
    }
};