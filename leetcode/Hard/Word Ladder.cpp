#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    wordList.push_back(beginWord);
    int n = wordList.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < n;++i)
        mp[wordList[i]] = i;

    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(n-1);
    dist[n-1] = 1;
    while (!q.empty())
    {
        string node = wordList[q.front()];
        int cst = dist[mp[node]];
        q.pop();

        for (int i = 0; i < node.size();++i)
        {
            char tmp = node[i];
            for (int c = 0; c < 26;++c)
            {
                if(node[i] != c + 'a')
                {
                    node[i] = c + 'a';
                    if(mp.find(node) != mp.end() && dist[mp[node]] == -1)
                    {
                        if(node == endWord)
                            return cst + 1;

                        dist[mp[node]] = cst + 1;
                        q.push(mp[node]);
                    }
                }
            }
            node[i] = tmp;
        }
    }
    return 0;
}