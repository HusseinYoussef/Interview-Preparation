#include <iostream>
#include <vector>

using namespace std;

class BrowserHistory {
public:
    string arr[5005];
    int cur, last;
    BrowserHistory(string homepage)
    {
        cur = last = 0;
        arr[cur] = homepage;
    }
    
    void visit(string url)
    {
        arr[++cur] = url;
        last = cur;
    }
    
    string back(int steps)
    {
        cur = max(cur - steps, 0);
        return arr[cur];
    }
    
    string forward(int steps)
    {
        cur = min(cur + steps, last);
        return arr[cur];
    }
};