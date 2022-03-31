#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions, vector<int> results)
{
    int n = competitions.size();
    unordered_map<string, int> mp;
    int mx = 0;
    string ans, team;
    for (int i = 0; i < n;++i)
    {
        if(results[i] == 0)
            team = competitions[i][1];
        else
            team = competitions[i][0];

        ++mp[team];
        if(mp[team] > mx)
        {
            mx = mp[team];
            ans = team;
        }
    }
    return ans;
}