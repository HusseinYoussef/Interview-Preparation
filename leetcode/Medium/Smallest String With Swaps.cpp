#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100005;
int par[N];
int find(int v)
{
    if(v == par[v])
        return v;
    return par[v] = find(par[v]);
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
{
    int n = pairs.size();
    for (int i = 0; i < N;++i)
        par[i] = i;
    for (int i = 0; i < n;++i)
    {
        int a = find(pairs[i][0]);
        int b = find(pairs[i][1]);
        if(a != b)
        {
            par[b] = a;
        }
    }
    vector<vector<int>>indices(s.size() + 1);
    vector<vector<char>> chars(s.size() + 1);
    for (int i = 0; i < s.size();++i)
    {
        int a = find(i);
        indices[a].push_back(i);
        chars[a].push_back(s[i]);
    }
    for (int i = 0; i < s.size();++i)
    {
        if(indices[i].size())
        {
            sort(chars[i].begin(), chars[i].end());
            for (int j = 0; j < chars[i].size();++j)
                s[indices[i][j]] = chars[i][j];
        }
    }
    return s;
}