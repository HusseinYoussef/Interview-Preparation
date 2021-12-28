#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
{
    int n = mat.size(), m = mat[0].size();
    priority_queue<pair<int,int>>pq;
    for(int i =0;i<n;++i)
    {
        int ones = 0;
        for(int j =0;j<m;++j)
        {
            if(mat[i][j] == 0)
                break;
            ones++;
        }
        pq.push({ones, i});
        if(pq.size() > k) pq.pop();
    }
    vector<int>ans;
    while(!pq.empty())
      ans.push_back(pq.top().second), pq.pop();
    reverse(ans.begin(), ans.end());
    return ans;   
}
