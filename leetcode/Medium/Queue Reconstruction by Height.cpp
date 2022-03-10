#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
    int n = people.size();
    sort(people.begin(), people.end());

    vector<vector<int>> ans(n);

    int cnt = 0;
    for (int i = 0;i<n;++i)
    {
        cnt = 0;
        for (int j = 0; j < n;++j)
        {
            if(cnt == people[i][1])
            {
                if(ans[j].size())
                    continue;
                ans[j] = people[i];
                break;
            }
            if(ans[j].size() == 0 || ans[j][0] == people[i][0])
                ++cnt;
        }
    }
    return ans;
}