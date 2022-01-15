#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int minJumps(vector<int>& arr)
{
    int n = arr.size();
    int cst[n+1];
    unordered_map<int, vector<int>>mp;
    memset(cst, -1, sizeof(cst));
    for(int i =0;i<n;++i)
    {
        mp[arr[i]].push_back(i);
    }

    queue<int> q;
    q.push(0);
    cst[0] = 0;
    while(!q.empty())
    {
        int idx = q.front();
        int cost = cst[idx];
        q.pop();
        if(idx + 1 < n && cst[idx+1] == -1)
        {
            cst[idx+1] = cost + 1;
            q.push(idx+1);
        }
        if(idx - 1 >= 0 && cst[idx-1] == -1)
        {
            cst[idx-1] = cost + 1;
            q.push(idx-1);
        }
        for(int i = 0;i<mp[arr[idx]].size();++i)
        {
            if(cst[mp[arr[idx]][i]] == -1)
            {
                cst[mp[arr[idx]][i]] = cost + 1;
                q.push(mp[arr[idx]][i]);
            }
        }
        mp[arr[idx]].clear();
        if(cst[n-1] != -1)
            break;
    }
    return cst[n-1];
}
