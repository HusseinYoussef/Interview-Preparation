#include <vector>
#include <algorithm>

using namespace std;

const int N = 1005;
int par[N];
int find(int v)
{
    if(par[v] == v)
        return v;
    return par[v] = find(par[v]);
}

int minCostConnectPoints(vector<vector<int>>& points)
{
    for (int i = 0; i < N;++i)
        par[i] = i;

    int n = points.size();
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n;++i)
    {
        for (int j = i + 1; j < n;++j)
        {
            int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.push_back({cost, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    int num = 0, ans = 0;
    for (int i = 0; i < edges.size();++i)
    {
        if(num == n-1)
            break;

        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int a = find(u);
        int b = find(v);
        if(a != b)
        {
            par[b] = a;
            ++num;
            ans += edges[i].first;
        }
    }
    return ans;
}