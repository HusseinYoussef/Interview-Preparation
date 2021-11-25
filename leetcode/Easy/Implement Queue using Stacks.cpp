#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {        
    }
    
    void push(int x) {
        s1.push(x);
    }

    void transfer()
    {
        if(s2.empty())
        {
            while(s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }    
    int pop() {
        transfer();
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        transfer();
        return s2.top();
    }
    
    bool empty() {
        return !(s1.size() || s2.size());
    }
};

int main()
{
    return 0;
}