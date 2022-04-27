#include <vector>
#include <unordered_map>

using namespace std;

int LCS(vector<int>& arr)
{
    int n = arr.size();
    unordered_map<int, bool> vis;
    for (int i = 0; i < n;++i)
        vis[arr[i]] = 1;

    int ans = 0;
    for (int i = 0; i < n;++i)
    {
        if(vis[arr[i]])
        {
            vis[arr[i]] = 0;
            int l = arr[i] - 1, r = arr[i] + 1;
            int len = 1;
            while(vis[r])
            {
                ++len;
                vis[r] = 0;
                ++r;
            }
            while(vis[l])
            {
                ++len;
                vis[l] = 0;
                --l;
            }
            ans = max(ans, len);
        }
    }
    return ans;
}