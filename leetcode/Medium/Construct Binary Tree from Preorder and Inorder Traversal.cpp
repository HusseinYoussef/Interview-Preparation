#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rootIdx = 0;
unordered_map<int, int> mp;
TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r)
{
    if(r < l)
        return nullptr;
    int root = preorder[rootIdx++];
    TreeNode *node = new TreeNode(root);

    node->left = solve(preorder, inorder, l, mp[root] - 1);
    node->right = solve(preorder, inorder, mp[root] + 1, r);
    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    for (int i = 0; i < inorder.size();++i)
        mp[inorder[i]] = i;
    int rootIdx = 0;
    return solve(preorder, inorder, 0, inorder.size() - 1);
}