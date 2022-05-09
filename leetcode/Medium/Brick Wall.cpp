#include <vector>
#include <unordered_map>

using namespace std;

int leastBricks(vector<vector<int>>& wall)
{
    int n = wall.size();
    int mx = 0;
    unordered_map<int, int>edges;

    for (int i = 0; i < n;++i)
    {
        int sum = 0;
        for (int j = 0; j < wall[i].size()-1;++j)
        {
            sum += wall[i][j];
            ++edges[sum];
            mx = max(mx, edges[sum]);
        }
    }
    return n - mx;
}