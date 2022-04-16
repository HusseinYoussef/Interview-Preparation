#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    // 1st Solution O(nlogn)
    int n = arrive.size(), m = depart.size();
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());

    int i = 0, j = 0;
    int cnt = 0;
    while(i < n && j < m)
    {
        if(arrive[i] < depart[j])
        {
            ++cnt;
            ++i;
        }
        else 
        {
            --cnt;
            ++j;
        }

        if(cnt > K)
            return false;
    }
    return true;

    // 2nd Solution O(nlogn)
    int n = arrive.size();
    map<int, int> mp;
    for (int i = 0; i < n;++i)
    {
        ++mp[arrive[i]];
        --mp[depart[i]];
    }
    int cnt = 0;
    for (auto &p:mp)
    {
        cnt += p.second;
        if(cnt > K)
            return false;
    }
    return true;
}