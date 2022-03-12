#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class MagicDictionary {
public:
    unordered_map<string, bool>mp;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i = 0;i<dictionary.size();++i)
            mp[dictionary[i]] = 1;
    }
    
    // O(N^2)
    bool search(string searchWord) {
        for(auto &s : mp)
        {
            int diff = 0;
            string tmp = s.first;
            if(tmp.size() != searchWord.size())
                continue;
            for(int i = 0;i<searchWord.size();++i)
            {
                if(tmp[i] != searchWord[i])
                    ++diff;
                if(diff > 1)
                    break;
            }
            if(diff == 1)
                return true;
        }
        return false;
    }
};

// Trie search O(26*N^2)
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
            node->childs[s[i]-'a'] = new TrieNode();
        node = node->childs[s[i] - 'a'];
    }
    node->isEnd = 1;
}

bool searchTrie(TrieNode* node, string &s)
{
    for (int i = 0; i < s.size();++i)
    {
        if(node->childs[s[i]-'a'] == nullptr)
            return false;
        node = node->childs[s[i] - 'a'];
    }
    return node->isEnd;
}

class MagicDictionary {
public:
    TrieNode *root;
    MagicDictionary()
    {
        root = nullptr;
    }
    
    void buildDict(vector<string> dictionary)
    {
        for (int i = 0; i < dictionary.size();++i)
            insert(root, dictionary[i]);
    }
    
    bool search(string searchWord)
    {
        for (int i = 0; i < searchWord.size();++i)
        {
            char tmp = searchWord[i];
            for (int c = 0; c < 26;++c)
            {
                if (c != tmp - 'a')
                {
                    searchWord[i] = c + 'a';
                    if(searchTrie(root, searchWord))
                        return true;
                }
            }
            searchWord[i] = tmp;
        }
        return false;
    }
};
