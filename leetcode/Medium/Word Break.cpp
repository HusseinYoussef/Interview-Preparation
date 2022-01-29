#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26;++i)
            children[i] = nullptr;
        isEnd = 0;
    }
};

void insert(TrieNode* cur, string &word)
{
    for (int i = 0; i < word.size();++i)
    {
        if(cur->children[word[i]-'a'] == nullptr)
            cur->children[word[i] - 'a'] = new TrieNode();
        cur = cur->children[word[i] - 'a'];
    }
    cur->isEnd = 1;
}

bool search(TrieNode* cur, string &word)
{
    for (int i = 0; i < word.size();++i)
    {
        if(cur->children[word[i]-'a'] == nullptr)
            return false;
        cur = cur->children[word[i] - 'a'];
    }
    return cur->isEnd;
}

int dp[305];
bool solve(TrieNode* root, string &s, int idx)
{
    if(idx == s.size())
        return 1;

    int &ret = dp[idx];
    if(~ret)
        return ret;

    ret = 0;
    string tmp = "";
    for (int i = idx; i < s.size();++i)
    {
        tmp += s[i];
        if(search(root, tmp))
        {
            ret |= solve(root, s, i + 1);
            if(ret)
                break;
        }
    }
    return ret;
}

bool wordBreak(string s, vector<string>& wordDict)
{
    TrieNode *root = new TrieNode();
    for (int i = 0; i < wordDict.size();++i)
        insert(root, wordDict[i]);
    memset(dp, -1, sizeof(dp));
    return solve(root, s, 0);

    // Bottom-Up
    // int dp[305];
    // dp[s.size()] = 1;
    // for (int idx = s.size() - 1; idx >= 0;--idx)
    // {
    //     string tmp = "";
    //     dp[idx] = 0;
    //     for (int i = idx; i < s.size();++i)
    //     {
    //         tmp += s[i];
    //         if(search(root, tmp))
    //             dp[idx] |= dp[i + 1];
    //         if(dp[idx])
    //             break;
    //     }
    // }
    // return dp[0];
}