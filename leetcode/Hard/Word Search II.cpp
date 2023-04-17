#include <vector>
#include <cstring>

using namespace std;

struct TrieNode
{
    TrieNode* childs[26];
    int isEnd;

    TrieNode()
    {
        for(int i = 0;i<26;++i)
            childs[i] = nullptr;
        isEnd = 0;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string &word, int idx)
    {
        TrieNode* cur = root;
        for(int i = 0;i<word.size();++i)
        {
            if (cur->childs[word[i] - 'a'] == nullptr)
                cur->childs[word[i] - 'a'] = new TrieNode();
            cur = cur->childs[word[i] - 'a'];
        }
        cur->isEnd = idx;
    }

    int n, m;
    bool vis[13][13];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool valid(int nx, int ny)
    {
        return nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny];
    }

    void dfs(vector<string> &ans, vector<string>& words, vector<vector<char>>& board, int x, int y, TrieNode* cur)
    {
        if (cur->isEnd)
        {
            ans.push_back(words[cur->isEnd - 1]);
            cur->isEnd = 0; // to avoid duplicates
        }

        vis[x][y] = 1;
        for(int i = 0;i<4;++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny) && cur->childs[board[nx][ny] - 'a'] != nullptr)
                dfs(ans, words, board, nx, ny, cur->childs[board[nx][ny] - 'a']);
        }
        vis[x][y] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        for(int i = 0;i<words.size();++i)
            insert(words[i], i + 1);

        n = board.size(), m = board[0].size();
        memset(vis, 0, sizeof(vis));
        vector<string> ans;
        for(int i = 0;i<n;++i)
        {
            for(int j = 0;j<m;++j)
            {
                if (root->childs[board[i][j] - 'a'] != nullptr)
                    dfs(ans, words, board, i, j, root->childs[board[i][j] - 'a']);
            }
        }

        return ans;      
    }
};
