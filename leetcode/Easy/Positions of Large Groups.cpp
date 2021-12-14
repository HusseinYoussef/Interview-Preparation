#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> largeGroupPositions(string s)
{
    vector<vector<int>>ans;
    int st = 0;
    int cnt = 1;
    for(int i =1;i<s.size();++i)
    {
        if(s[i] == s[i-1])
            cnt++;
        if(s[i] != s[i-1] || i == s.size()-1)
        {
            if(cnt >= 3)
                ans.push_back({st, st+cnt-1});
            st = i;
            cnt = 1;
        }
    }
    return ans;
}
