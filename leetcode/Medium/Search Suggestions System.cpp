#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct TrieNode
{
    TrieNode *childs[26];
    bool isEnd;

    TrieNode()
    {
        for (int i = 0; i < 26;++i)
            childs[i] = nullptr;
        isEnd = false;
    }
};

void insert(TrieNode* node, string &s)
{
    for (int i = 0; i < s.size();++i)
    {
        if (node->childs[s[i] - 'a'] == nullptr)
            node->childs[s[i] - 'a'] = new TrieNode();

        node = node->childs[s[i] - 'a'];
    }
    node->isEnd = true;
}

void dfs(vector<string> &res, TrieNode* node, string &word)
{
    if(res.size() == 3)
        return;
    
    if(node->isEnd)
        res.push_back(word);

    for (int i = 0; i < 26;++i)
    {
        if(node->childs[i] != nullptr)
        {
            word.push_back(i + 'a');
            dfs(res, node->childs[i], word);
            word.pop_back();
        }
    }
}

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
{
    int n = products.size();
    TrieNode* root = new TrieNode();

    for (int i = 0; i < n;++i)
        insert(root, products[i]);

    vector<vector<string>> ans;
    TrieNode *cur = root;
    string prefix = "";
    for (int i = 0;i<searchWord.size();++i)
    {
        cur = cur ? cur->childs[searchWord[i] - 'a'] : nullptr;
        if (cur == nullptr)
            ans.push_back({});
        else
        {
            vector<string> tmp;
            prefix += searchWord[i];
            dfs(tmp, cur, prefix);
            ans.push_back(tmp);
        }
    }
    return ans;
}