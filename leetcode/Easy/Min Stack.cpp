#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class MinStack {
public:

    vector<pair<int, int>> st;
    MinStack()
    {
    }
    
    void push(int val)
    {
        if(!st.size())
            st.push_back({val, val});
        else
            st.push_back({val, min(st[st.size()-1].second, val)});
    }
    
    void pop()
    {
        st.pop_back();
    }
    
    int top()
    {
        return st[st.size()-1].first;
    }
    
    int getMin()
    {
        return st[st.size()-1].second;
    }
};

int main()
{
    return 0;
}