#include <iostream>

using namespace std;

class WordDictionary {
public:

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
            if (cur->children[word[i] - 'a'] == nullptr)
                cur->children[word[i] - 'a'] = new TrieNode();
            cur = cur->children[word[i] - 'a'];
        }
        cur->isEnd = 1;
    }

    bool find(TrieNode* cur, string &word, int idx)
    {
        for (int i = idx; i < word.size();++i)
        {
            if(word[i] == '.')
            {
                for (int j = 0; j < 26;++j)
                {
                    if(cur->children[j] != nullptr)
                    {
                        if(find(cur->children[j], word, i + 1))
                            return true;
                    }
                }
                return false;
            }
            else
            {
                if(cur->children[word[i]-'a'] == nullptr)
                    return false;
                cur = cur->children[word[i] - 'a'];
            }
        }
        return cur->isEnd;
    }

    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        insert(root, word);
    }
    
    bool search(string word) {
        return find(root, word, 0);
    }
};