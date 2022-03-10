#include <vector>
#include <unordered_map>

using namespace std;

void dfs(vector<int> &ans, unordered_map<int, vector<int>> &G, int p)
{
    ans.push_back(p);
    for (int i = 0; i < G[p].size();++i)
        dfs(ans, G, G[p][i]);
}

vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
{
    int n = pid.size();
    vector<int> ans;
    unordered_map<int, vector<int>> G;
    for (int i = 0; i < n;++i)
        G[ppid[i]].push_back(pid[i]);
    dfs(ans, G, kill);
    return ans;
}