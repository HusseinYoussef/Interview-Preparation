#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int mod(string &s, int r)
{
    int rem = 0;
    for (int i = 0; i< s.size();++i)
    {
        rem = (rem * 10 + (s[i] - '0')) % r;
    }
    return rem;
}

string smallestMultiple(int n)
{
    unordered_map<int, bool> vis;
    queue<string> q;
    q.push("1");
    while (!q.empty())
    {
        string node = q.front();
        q.pop();

        int rem = mod(node, n);
        if(rem == 0)
            return node;

        if(vis[rem])
            continue;

        vis[rem] = 1;
        q.push(node + "0");
        q.push(node + "1");
    }
    
    return "";
}