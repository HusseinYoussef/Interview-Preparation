#include <stack>

using namespace std;

class StockSpanner {
public:
    // {val, cnt (how many values <= current val that got removed (execluding this value))}
    stack<pair<int, int>> st;
    StockSpanner()
    {}

    int next(int price)
    {
        int cnt = 0;
        while(st.size() && st.top().first <= price)
        {
            cnt += st.top().second + 1;
            st.pop();
        }
        st.push({price, cnt});
        return cnt + 1;
    }
};