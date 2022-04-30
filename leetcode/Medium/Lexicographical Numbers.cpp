#include <vector>

using namespace std;

void dfs(vector<int> &ans, int num, int n)
{
    if(num > n)
        return;

    if(num)
        ans.push_back(num);

    for (int i = 0; i <= 9;++i)
    {
        if(num == 0 && i == 0)
            continue;
        dfs(ans, num * 10 + i, n);
    }
}

vector<int> lexicalOrder(int n)
{
    vector<int> ans;
    dfs(ans, 0, n);
    return ans;
}