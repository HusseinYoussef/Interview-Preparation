#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    wordList.push_back(beginWord);
    int n = wordList.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < n;++i)
        mp[wordList[i]] = i;

    vector<int> dist(n + 1, -1);
    vector<vector<int>> paths;
    vector<vector<string>> ans;
    queue<vector<int>> q;
    q.push({n-1});
    dist[n-1] = 1;
    while (!q.empty())
    {
        vector<int> path = q.front();
        string node = wordList[path.back()];
        int cst = dist[mp[node]];
        q.pop();

        if(node == endWord)
            continue;

        for (int i = 0; i < node.size();++i)
        {
            char tmp = node[i];
            for (int c = 0; c < 26;++c)
            {
                if(node[i] != c + 'a')
                {
                    node[i] = c + 'a';
                    if(mp.find(node) != mp.end() && (dist[mp[node]] == -1 || dist[mp[node]] == cst+1))
                    {
                        path.push_back(mp[node]);
                        if(node == endWord)
                            paths.push_back(path);
                        dist[mp[node]] = cst + 1;
                        q.push(path);
                        path.pop_back();
                    }
                }
            }
            node[i] = tmp;
        }
    }
    for (int i = 0; i < paths.size();++i)
    {
        vector<string> vec;
        for (int j = 0; j < paths[i].size();++j)
            vec.push_back(wordList[paths[i][j]]);
        ans.push_back(vec);
    }
    return ans;
}