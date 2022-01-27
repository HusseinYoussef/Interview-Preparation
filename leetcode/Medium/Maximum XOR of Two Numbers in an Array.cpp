#include <vector>

using namespace std;

struct TrieNode
{
    TrieNode* children[2];
    TrieNode(){
        for (int i = 0; i < 2;++i)
            children[i] = nullptr;
    }
};

void insert(TrieNode* cur, int num)
{
    for (int i = 31; i >= 0;--i)
    {
        bool bit = num & (1 << i);
        if(cur->children[bit] == nullptr)
            cur->children[bit] = new TrieNode();
        cur = cur->children[bit];
    }
}

int search(TrieNode* cur, int num)
{
    int res = 0;
    for (int i = 31; i >= 0;--i)
    {
        bool bit = num & (1 << i);
        if(cur->children[!bit] != nullptr) // different bits -> set ith bit
        {
            cur = cur->children[!bit];
            res |= (1 << i);
        }
        else
            cur = cur->children[bit];
    }
    return res;
}

TrieNode *root;
int findMaximumXOR(vector<int>& nums)
{
    root = new TrieNode();
    int n = nums.size(), mx = 0;
    for (int i = 0; i < n;++i)
    {
        insert(root, nums[i]);
        mx = max(mx, search(root, nums[i]));
    }
    return mx;
}