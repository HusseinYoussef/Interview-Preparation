#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

int imp[2005];
int vis[2005];
int ans = 0;
void dfs(vector<vector<int>> &G, int id)
{
    vis[id] = 1;
    ans += imp[id];
    for(int i = 0;i<G[id].size();++i)
    {
        if(!vis[G[id][i]])
            dfs(G, G[id][i]);
    }
}

int getImportance(vector<Employee*> employees, int id)
{
    memset(vis, 0, sizeof(vis));
    memset(imp, 0, sizeof(imp));
    vector<vector<int>> G(2005);

    for(int i =0;i<employees.size();++i)
    {
        imp[employees[i]->id] = employees[i]->importance;
        for(int j = 0;j<employees[i]->subordinates.size();++j)
        {
            G[employees[i]->id].push_back(employees[i]->subordinates[j]);
        }
    }
    dfs(G, id);
    return ans;
}
