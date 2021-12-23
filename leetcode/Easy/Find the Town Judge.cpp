#include <iostream>
#include <vector>

using namespace std;

int findJudge(int n, vector<vector<int>>& trust)
{
    vector<int> indegree(1001, 0);
    vector<int> outdegree(1001, 0);
    for (int i = 0; i < trust.size();++i)
    {
        int v = trust[i][0], u = trust[i][1];
        indegree[u]++;
        outdegree[v]++;
    }
    int ans = -1;
    for (int i = 1; i <= n;++i)
    {
        if(indegree[i] == n-1 && outdegree[i] == 0)
        {
            if(ans != -1)
                return -1;
            ans = i;
        }
    }
    return ans;
}