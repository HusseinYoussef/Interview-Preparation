#include <vector>
#include <cstring>

using namespace std;

int par[205];
int find(int v)
{
    if(v == par[v])
        return v;
    return par[v] = find(par[v]);
}

int findCircleNum(vector<vector<int>>& isConnected)
{
    int n = isConnected.size();
    memset(par, -1, sizeof(par));
    for (int i = 0; i < n;++i)
        par[i] = i;
    for (int i = 0; i < n;++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if(isConnected[i][j])
            {
                int a = find(i);
                int b = find(j);
                if(a != b)
                    par[b] = a;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n;++i)
        ans += (i == par[i]);
    return ans;
}