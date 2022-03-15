#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans = 0;
// excess coins in the subtree of node including node itself
int dfs(TreeNode* node)
{
    if(node == nullptr)
        return 0;

    int l = dfs(node->left);
    int r = dfs(node->right);
    ans += abs(l) + abs(r);
    return node->val + l + r - 1;
}

int distributeCoins(TreeNode* root)
{
    dfs(root);
    return ans;
}