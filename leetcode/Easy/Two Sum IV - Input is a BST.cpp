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

bool dfs(TreeNode* node, int target, TreeNode* picked)
{
    if(!node)
        return false;
    if(node->val == target && node != picked)
        return true;
    if(target > node->val)
        return dfs(node->right, target, picked);
    return dfs(node->left, target, picked);
}

bool rec(TreeNode* node, TreeNode* root, int k)
{
    if(!node)
        return false;
    int val = k - node->val;
    if(dfs(root, val, node))
        return true;
    return rec(node->left, root, k) || rec(node->right, root, k);
}

bool findTarget(TreeNode* root, int k)
{
    return rec(root, root, k);
}