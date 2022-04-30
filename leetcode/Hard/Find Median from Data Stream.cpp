#include <vector>
#include <queue>

using namespace std;

priority_queue<int> maxpq;    // left portion
priority_queue<int, vector<int>, greater<int>> minpq;  // right portion

void addNum(int num)
{
    if(maxpq.empty() || num <= maxpq.top())
        maxpq.push(num);
    else if(maxpq.size() && num > maxpq.top())
        minpq.push(num);

    if((int)maxpq.size() - (int)minpq.size() > 1)
    {
        int top = maxpq.top();
        maxpq.pop();
        minpq.push(top);
    }
    else if((int)minpq.size() - (int)maxpq.size() > 1)
    {
        int top = minpq.top();
        minpq.pop();
        maxpq.push(top);
    }
}

double findMedian()
{
    int total = maxpq.size() + minpq.size();
    if(total & 1)
    {
        if(maxpq.size() > minpq.size())
            return maxpq.top();
        else
            return minpq.top();
    }
    else
        return (maxpq.top() + minpq.top()) * 1.0 / 2;
}