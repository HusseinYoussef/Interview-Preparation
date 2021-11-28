#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
{
    queue<vector<int>> q;
    vector<vector<int>> ans;
    vector<int> s;
    s.push_back(0);
    q.push(s);
    while(!q.empty())
    {
        vector<int> vec = q.front();
        q.pop();
        int node = vec[vec.size() - 1];
        if(node == graph.size()-1)
        {
            ans.push_back(vec);
            continue;
        }
        vec.push_back(0);
        for (int i = 0; i < graph[node].size();++i)
        {
            vec[vec.size() - 1] = graph[node][i];
            q.push(vec);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> vec(4);
    vec[0] = {1, 2};
    vec[1] = {3};
    vec[2] = {3};
    allPathsSourceTarget(vec);
    return 0;
}