#include <vector>
#include <queue>

using namespace std;

string alienOrder(vector<string> &words)
{
    int n = words.size();

    if (n == 1)
        return words[0];

    vector<vector<int>> G(26);
    vector<int> indegree(26, -1);
    int chars = 0;
    for (int i = 0;i<n;++i)
    {
        for(int j = 0;j<words[i].size();++j)
        {
            if (indegree[words[i][j] - 'a'] == -1)
                ++chars;
            indegree[words[i][j] - 'a'] = 0;
        }
    }

    for(int i = 0;i<n-1;++i)
    {
        int j = i + 1;
        int k = 0;
        bool f = 0;
        while (k < min(words[i].size(), words[j].size()))
        {
            if (words[i][k] != words[j][k])
            {
                int u = words[i][k] - 'a';
                int v = words[j][k] - 'a';

                G[u].push_back(v);
                ++indegree[v];
                f = 1;
                break;
            }
            ++k;
        }
        if (!f && words[j].size() < words[i].size()) // j is prefix of i
            return "";
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0 ;i<26;++i)
    {
        if (indegree[i] == 0)
            pq.push(i);
    }

    string ans = "";
    while(!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        ans += node + 'a';
        --chars;

        for (int i = 0;i<G[node].size();++i)
        {
            --indegree[G[node][i]];
            if (indegree[G[node][i]] == 0)
                pq.push(G[node][i]);
        }
    }
    if (chars == 0)
        return ans;
    return "";
}
