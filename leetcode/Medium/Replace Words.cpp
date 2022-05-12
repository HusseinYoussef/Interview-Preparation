#include <iostream>
#include <vector>

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

void insert(TrieNode* node, string &s)
{
    for (int i = 0; i < s.size();++i)
    {
        if(node->childs[s[i]-'a'] == nullptr)
            node->childs[s[i] - 'a'] = new TrieNode();
        node = node->childs[s[i] - 'a'];
    }
    node->isEnd = 1;
}

string ans = "";
void search(TrieNode* node, string &s)
{
    string prefix = "";
    for (int i = 0; i < s.size();++i)
    {
        if(node->childs[s[i]-'a'] != nullptr)
        {
            prefix += s[i];
            node = node->childs[s[i] - 'a'];
        }
        else
            break;
     
        if(node->isEnd)
        {
            ans = prefix;
            return;
        }
    }
}

string replaceWords(vector<string>& dictionary, string sentence)
{
    TrieNode *root = new TrieNode;

    int n = dictionary.size();
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);

    string tmp = "";
    string res = "";
    for (int i = 0; i < sentence.size();++i)
    {
        if(sentence[i] != ' ')
            tmp += sentence[i];
        if(sentence[i] == ' ' || i == sentence.size()-1)
        {
            ans = "";
            search(root, tmp);
            if(res.size())
                res += ' ';
            if(ans.size())
                res += ans;
            else
                res += tmp;
            tmp = "";
        }
    }
    return res;
}