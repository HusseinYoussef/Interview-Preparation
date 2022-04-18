#include <stack>

using namespace std;

stack<int> sortStack(stack<int>& st)
{
    // O(N^2) Time, O(N) Space
    stack<int> tmp;

    while(!st.empty())
    {
        int val = st.top();
        st.pop();

        while(tmp.size() && tmp.top() < val)
        {
            st.push(tmp.top());
            tmp.pop();
        }
        tmp.push(val);
    }
    return tmp;
}

/*
Recursion O(N^2) Time, O(N) Space

void sortandinsert(stack<int>& st, int data)
{
    if(st.empty() || data < st.top())
    {
        st.push(data);
        return;
    }
    int tmp = st.top();
    st.pop();
    sortandinsert(st, data);
    st.push(tmp);
}

stack<int> sortStack(stack<int>& st)
{
    if(st.size())
    {
        int tmp = st.top();
        st.pop();
        sortStack(st);
        sortandinsert(st, tmp);
    }
    return st;
}
*/