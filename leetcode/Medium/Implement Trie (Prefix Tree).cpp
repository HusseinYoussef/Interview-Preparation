#include <iostream>
#include <vector>

using namespace std;

struct TrieNode
{
    TrieNode* childs[26];
    bool isEnd;
    TrieNode() 
    {
        for (int i = 0; i < 26;++i)
            childs[i] = nullptr;
        isEnd = 0;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode *tmp = root;
        for (int i = 0; i < word.size();++i)
        {
            if(tmp->childs[word[i]-'a'] == nullptr)
                tmp->childs[word[i] - 'a'] = new TrieNode();
            tmp = tmp->childs[word[i] - 'a'];
        }
        tmp->isEnd = 1;
    }
    
    bool search(string word)
    {
        TrieNode *tmp = root;
        for (int i = 0; i < word.size();++i)
        {
            if(tmp->childs[word[i]-'a'] == nullptr)
                return false;
            tmp = tmp->childs[word[i] - 'a'];
        }
        return tmp->isEnd;
    }
    
    bool startsWith(string prefix)
    {
        TrieNode *tmp = root;
        for (int i = 0; i < prefix.size();++i)
        {
            if(tmp->childs[prefix[i]-'a'] == nullptr)
                return false;
            tmp = tmp->childs[prefix[i] - 'a'];
        }
        return true;
    }
};