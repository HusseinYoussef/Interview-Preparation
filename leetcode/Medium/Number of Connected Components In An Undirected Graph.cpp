#include <vector>

using namespace std;

class ConnectingGraph3 {
public:

    int par[100005];
    int cc = 0;
    int find(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = find(par[u]);
    }

    ConnectingGraph3(int n)
    {
        cc = n;
        for(int i = 0;i<=n;++i)
            par[i] = i;
    }
    void connect(int a, int b)
    {
        int v = find(a);
        int u = find(b);

        if (v != u)
        {
            par[u] = v;
            --cc;
        }
    }

    int query()
    {
        return cc;
    }
};
