#include <iostream>
#include <vector>

using namespace std;

vector<string> findRelativeRanks(vector<int>& score)
{
    int n = score.size();
    priority_queue<pair<int,int>>pq;
    for(int i =0;i<score.size();++i)
    {
        pq.push({score[i], i});
    }
    vector<string> ans(n);
    int i=1;
    while(!pq.empty())
    {
        string s;
        if(i == 1)
            s = "Gold Medal";
        else if(i == 2)
            s = "Silver Medal";
        else if(i == 3)
            s = "Bronze Medal";
        else
            s = to_string(i);
        ans[pq.top().second] = s;
        pq.pop();
        ++i;
    }

    return ans;        
}
