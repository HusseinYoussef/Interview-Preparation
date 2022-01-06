#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

struct TrieNode
{
    TrieNode *childs[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26;++i)
            childs[i] = nullptr;
        isEnd = 0;
    }
};

void insert(string &s)
{
    TrieNode *tmp = root;
    for (int i = 0; i < s.size();++i)
    {
        if(tmp->childs[s[i]-'a'] == nullptr)
            tmp->childs[s[i] - 'a'] = new TrieNode();
        tmp = tmp->childs[s[i] - 'a'];
    }
    tmp->isEnd = 1;
}

bool search(string &s)
{
    TrieNode *tmp = root;
    for (int i = 0; i < s.size();++i)
    {
        if(tmp->childs[s[i]-'a'] == nullptr)
            return false;
        tmp = tmp->childs[s[i] - 'a'];
    }
    return tmp->isEnd;
}

TrieNode *root;
int dp[305];
bool ans = 0;
// O(N^2)
bool solve(string &s, int start)
{
    if(start == s.size() || ans)
        return true;

    int &ret = dp[start];
    if(~ret)
        return ret;

    string tmp = "";
    for (int i = start; i < s.size();++i)
    {
        if(ans)
            break;
        tmp += s[i];
        if(search(tmp))
        {
            ans |= solve(s, i + 1);
        }
    }
    return ret = ans;
}

bool wordBreak(string s, vector<string>& wordDict)
{
    root = new TrieNode;
    for (int i = 0; i < wordDict.size();++i)
        insert(wordDict[i]);
    memset(dp, -1, sizeof(dp));
    return solve(s, 0);
}