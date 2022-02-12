#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    int n = wordList.size();
    unordered_map<string, int> dist;
    for(int i =0;i<n;++i)
        dist[wordList[i]] = 0;
    if(dist.find(endWord) == dist.end())
        return 0;
    dist[beginWord] = 1;
    queue<string>q;
    q.push(beginWord);
    while(!q.empty())
    {
        string node = q.front();
        q.pop();
        int cost = dist[node];
        for(int i = 0;i<node.size();++i)
        {    
            for(int j = 0;j<26;++j)
            {
                if(j != node[i]-'a')
                {
                    string tmp = node;
                    tmp[i] = j + 'a';
                    if(dist.find(tmp) != dist.end() && dist[tmp] == 0)
                    {
                        dist[tmp] = cost + 1;
                        q.push(tmp);
                    }
                }
            }
        }
    }
    return dist[endWord];
}
