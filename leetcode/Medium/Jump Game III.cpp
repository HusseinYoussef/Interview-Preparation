#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool vis[50004];
bool ans = false;
void dfs(vector<vector<int>> &G, int idx)
{
    if(ans)
        return;
    vis[idx] = 1;
    for(int i=0; i<G[idx].size(); ++i)
    {
        if(G[idx][i] == idx)
        {
            ans |= true;
            return;
        }
        if(!vis[G[idx][i]])
            dfs(G, G[idx][i]);
    }
}

bool canReach(vector<int>& arr, int start) 
{
    vector<vector<int>> G(50004);
    memset(vis, 0, sizeof(vis));
    for(int i =0;i<arr.size();++i)
    {
        if(i+arr[i] < arr.size())
            G[i].push_back(i+arr[i]);
        if(i-arr[i] >= 0)
            G[i].push_back(i-arr[i]);
    }
    dfs(G, start);
    return ans;
}
