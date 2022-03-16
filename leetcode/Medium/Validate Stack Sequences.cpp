#include <vector>
#include <stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
    int n = pushed.size();
    stack<int> st;
    for(int i = 0, j=0;i<n || j<n;)
    {
        if(st.size() && j < n && popped[j] == st.top())
        {
            st.pop();
            ++j;
        }
        else if(i < n)
        {
            st.push(pushed[i]);
            ++i;
        }
        else
            return false;
    }
    return st.empty();
}
