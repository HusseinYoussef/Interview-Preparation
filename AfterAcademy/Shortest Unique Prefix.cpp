#include <iostream>
#include <vector>

using namespace std;

struct TrieNode
{
    TrieNode *childs[26];
    int cnt;
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26;++i)
            childs[i] = nullptr;
        cnt = 0;
        isEnd = 0;
    }
};

void insert(TrieNode* node, string &s)
{
    for (int i = 0; i < s.size();++i)
    {
        int idx = s[i] - 'a';
        if(node->childs[idx] == nullptr)
            node->childs[idx] = new TrieNode();

        ++node->childs[idx]->cnt;
        node = node->childs[idx];
    }
    node->isEnd = 1;
}

int find(TrieNode* node, string &s)
{
    for (int i = 0; i < s.size();++i)
    {
        int idx = s[i] - 'a';
        if(node->childs[idx]->cnt == 1)
            return i + 1;
        node = node->childs[idx];
    }
    return 0;
}

vector<string> shortestUniquePrefix(vector<string>& arr)
{
    TrieNode* root = new TrieNode();
    int n = arr.size();
    for (int i = 0; i < n;++i)
        insert(root, arr[i]);

    vector<string> ans;
    for (int i = 0; i < n;++i)
    {
        ans.push_back(arr[i].substr(0, find(root, arr[i])));
    }
    return ans;
}